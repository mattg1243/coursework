# part 1


def solar_payback_period(systemCost, energyCost, taxCredit):
    return (systemCost * (1 - taxCredit)) / energyCost


calcCount = 0

initialCost = float(input("Total initial cost of the system (in USD, -1 to exit) : "))

while initialCost != -1:
    energyAnn = float(input("Expected yearly energy bill (in USD) : "))
    taxCred = float(input("Tax credit percentage to apply (as a decimal number) : "))

    payback_period = solar_payback_period(initialCost, energyAnn, taxCred)
    print(f"The expected payback period of this system is :{payback_period: .2f} years")

    # part 2

    initCostOut = f"Initial Cost : ${initialCost: .2f}"
    taxCredOut = f"Tax Credit :{taxCred: .2f}"
    energyAnnOut = f"Annual Energy Bill : ${energyAnn: .2f}"
    paybackOut = f"Payback Period :{payback_period: .2f} years"

    outputList = [initCostOut, taxCredOut, energyAnnOut, paybackOut]
    outputFile = open("solar.txt", mode='a')

    for i in range(4):
        outputFile.write(outputList[i] + '\n')

    outputFile.write("-----------------------------\n")
    outputFile.close()
    calcCount += 1

    initialCost = float(input("Total initial cost of the system (in USD, -1 to exit) : "))

print(f"Wrote a total of {calcCount} calculations to solar.txt\n")
