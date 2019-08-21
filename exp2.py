print("Hello World")
import scipy as sp
data = sp.genfromtxt("web_traffic.tsv", delimiter="\t")

print(data.shape)

x = data[:,0]
y = data[:,1]

x = x[~sp.isnan(y)]
y = y[~sp.isnan(y)]

import matplotlib.pyplot as plt

plt.scatter(x,y)
plt.title("Web traffic")
plt.xlabel("time")
plt.ylabel("hits/hour")
plt.xticks([w*7*24 for w in range(10)], ['week %i' %w for w in range(10)])

plt.autoscale(tight=True)
plt.grid()
plt.show()