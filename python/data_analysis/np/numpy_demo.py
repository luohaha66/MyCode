import numpy as np


t1 = np.arange(12)
print(t1.shape)
print(t1.dtype)
t3 = t1.reshape((2, 6))
print(t3)
print(t3.T)
print(t3.transpose())

t2 = np.array([[1, 2, 3], [4, 5, 6]])
print(t2)
print(t2.shape)
t2 = t2.flatten()
print(t2)
print(t2+2)

t3 = np.arange(5)
t4 = np.arange(5)
print(t3 + t4)
t5 = np.arange(12).reshape((3, 4))
t6 = np.arange(4)
print(t5 + t6)
t6 = np.arange(3).reshape((3, 1))
print(t5 + t6)

import random
t7 = np.array([random.random() for _ in range(10)])
print(t7)
print(np.round(t7, 2))


