print("Hello world")
import pandas as pd

data = pd.read_csv("play_tennis.csv", delimiter=",")
data.head(5)
data.tail(5)

data.iloc[3:7]
data.iloc[:,0:1]
data.iloc[:,0:5]
data.iloc[:,2:3]
data.iloc[3:4,2:3]

data.Outlook
len(data)
print(data)