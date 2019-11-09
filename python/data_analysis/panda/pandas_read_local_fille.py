import pandas as pd
# from pymongo import MongoClient

df = pd.read_csv('1.csv')
print(df)

# client = MongoClient()
# collection = client['douban']['tv1']
# data = list(collection.find())
# print(data)
