filename = "vaccinationsbyzip-table-1.csv"
header = None

highest = 0
lowest = 100000
zipHigh = 0
zipLow = 0
totalSum = 0
count = 0

zipToCheck = int(input("If you want a check a specific zip code, type it here. Otherwise, type -1: "))
checkPerc = 0

# column [0] == zip, column [8] == percentage

with open(filename, 'r') as inputfile:
    for line in inputfile:
        if header is None:
            header = line
            continue

        line = line.split(',')

        if line[0] == '' or line[8] == '':
            continue

        zipCode = int(line[0])
        vaxPerc = float(line[8])

        if zipToCheck != -1:
            if zipCode == zipToCheck:
                checkPerc = vaxPerc

        if vaxPerc > highest:
            highest = vaxPerc
            zipHigh = zipCode

        elif vaxPerc < lowest:
            lowest = vaxPerc
            zipLow = zipCode

        totalSum += vaxPerc
        count += 1

vaxAvg = totalSum / count * 100

print(f"The average vaccination rate in CA is %{vaxAvg: .2f}.\n"
      f"The zip code with the highest percentage is {zipHigh} at %{highest * 100: .2f}.\n"
      f"The zip code with the lowest percentage is  {zipLow} at %{lowest * 100: .2f}.\n"
      f"Zip code {zipToCheck} has a vaccination rate of %{checkPerc * 100: .2f}")
