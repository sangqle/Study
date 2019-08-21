print("Hello world")

import scipy as sp
data = sp.genfromtxt("baitap1.csv", delimiter=",")
print(data)

print(data[:,2])
print(data[4:10,:])
print(data[4:5,0:2])

for i in range(0,50):
  if i % 2 == 0:
    print(i)
	
x = data[:,1]
y = data[:,2]

import matplotlib.pyplot as plt

plt.scatter(x,y)
plt.show()