import requests
import pandas as pd
import json


apiKey = 'fknfxin2au0uYdBL5zLJLnjPxEaxj3Hv'
url = 'https://api.nytimes.com/svc/mostpopular/v2/shared/1/facebook.json?api-key=' + apiKey
data = []

pop_articles = requests.get(url).json()
headers = list(requests.get(url).json())

json_status = pop_articles['status']
mydata = {'published_date': [], 'nytdsection': [], 'title': [], 'abstract': []}
media = []

print('Headers : ', headers,
      '\npop_articles : ', pop_articles,
      '\nAPI status : ', json_status)

# print(df.head())
print(type(pop_articles))
for news_data in pop_articles['results']:
    if 'published_date' in news_data:
        mydata['published_date'].append(news_data['published_date'])

    if 'nytdsection' in news_data:
        mydata['nytdsection'].append(news_data['nytdsection'])

    if 'title' in news_data:
        mydata['title'].append(news_data['title'])

    if 'abstract' in news_data:
        mydata['abstract'].append(news_data['abstract'])

    # if 'media' in news_data:
    #    media.append(news_data)

print('pub date : ', mydata['published_date'],
      '\nsection : ', mydata['nytdsection'],
      '\ntitle : ', mydata['title'],
      '\nabstract : ', mydata['abstract'])