import numpy as np

# create a zero array
zero = np.zeros((10, 1))
print(zero)
one = np.ones((10, 1))
print(one)

square = np.eye(5)
print(square)

# get the max or min pos in each row or each col
print(np.argmax(square, axis=0))
print(np.argmax(square, axis=1))

# uniform distribution
print(np.random.rand(2, 3))
# Normal distribution
print(np.random.randn(2, 3))
print(np.random.randint(10, 20, (2, 3)))
print(np.random.uniform(10, 20, (2, 3)))

# set random seed
np.random.seed(10)

"""
in numpy:
no copy, change a always change b
a = b, a = b[:]
copy
a = b.copy()
"""
