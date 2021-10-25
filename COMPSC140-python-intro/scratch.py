"""
base = int(input("Please enter a base : "))
exp = int(input("Please enter an exponent : "))
floatExp = float(exp)
answer = base ** exp

print(answer)
print("exp is of type : ", type(floatExp))

salePrice = 3.5694
stringy = f"The sale price is now {salePrice:.2f} for a limited time only!!"
print(stringy)


SECRET = 3
guess = input("What do you think the secret number is? : ")

while guess != str(SECRET):
    if int(guess) > SECRET:
        guess = input(f"The number {guess} is too big, try a smaller number : ")
    else:
        guess = input(f"The number {guess} is too small, try a bigger number : ")

print("Congrats, you finally got it!")


candles = [4, 3, 3, 4, 1, 2]
print(max(candles))


import math
import random

count = 4
while count < 12:
    print("counting")
    count = count + 2


list = ["what", "the", "fuck"]

listRep = list * 3
print(listRep)

bsList = list + listRep
list.sort()
print(list)


import requests
import pandas as pd

pd.set_option('display.max_rows', None)
pd.set_option('display.max_columns', None)
pd.set_option('display.width', None)
pd.set_option('display.max_colwidth', None)

apiKey = 'fknfxin2au0uYdBL5zLJLnjPxEaxj3Hv'
url = 'https://api.nytimes.com/svc/mostpopular/v2/shared/1/facebook.json?api-key=' + apiKey
data = []

pop_articles = requests.get(url).json()
headers = list(requests.get(url).json())

json_status = pop_articles['status']
mydata = {'published_date': [], 'nytdsection': [], 'title': [], 'abstract': []}
media = []

print('Headers : ', headers,
      '    ---    pop_articles : ', pop_articles,
      '    ---    API status : ', json_status)

df = pd.DataFrame(data)

# print(df.head())

for news_data in pop_articles:
    if 'publisher_date' in news_data:
        mydata['published_date'].append(news_data['published_date'])

    if 'nytdsection' in news_data:
        mydata['nytdsection'].append(news_data['nytdsection'])
        
    if 'title' in news_data:
        mydata['title'].append(news_data['title'])
        
    if 'abstract' in news_data:
        mydata['abstract'].append(news_data['abstract'])
        
    # if 'media' in news_data:
    #    media.append(news_data)

print(mydata)


s = 'yo'
s.lstrip()

bridges = ['golden', 'bay', 'carquinez']
bridges.remove('bay')
print(bridges)

s.isalpha()

"""
value1 = 3.0
value2 = 12

print(value1*value2, 'tab this\ttab')


def movecaps(string):
    ulist = []
    llist = []
    nlist = []
    for l in string:
        if l.isnumeric():
            nlist.append(l)
        elif l.upper() == l:
            ulist.append(l)
        else:
            llist.append(l)

    rstr = ''.join(nlist + llist + ulist)
    return rstr


print(movecaps('AeBsCD'))
print(movecaps('asdHEYfkj23ALKJ324'))
