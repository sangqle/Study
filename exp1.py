print("Hello Python")
import numpy as np

a = np.array([0, 1, 2, 3, 4, 5])
print(a)
print(a.ndim)
print(a.shape)
# print(a[a>2])
a[a>2] = 10
b = a.reshape((3, 2))
print(b)