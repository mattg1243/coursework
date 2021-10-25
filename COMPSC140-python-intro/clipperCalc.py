import struct

FEE = 3
cash = float(input("How much money do you have? : "))
age = int(input("How old are you? : "))

if cash < 4.25:
    print("The minimum amount allowed on this machine is 4.25, "
          "please insert more cash")
elif cash > 250:
    print("The maximum amount allowed on this machine is 250, "
          "please try again with a valid amount")
else:
    loadedAmount = cash - FEE
    print(f"With a fee of ${FEE: .2F}, ${loadedAmount: .2F} will be "
          f"loaded onto your Clipper card")
    if 5 <= age <= 18:
        print("You are eligible for a youth discount")
    elif age >= 65:
        print("You are eligible for a senior discount")
    else:
        print("You are not eligible for any discounts")


