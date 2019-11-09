import numpy as np

txt1 = np.loadtxt('1.csv', skiprows=1, delimiter=',')
print(txt1)

# get rows
print(txt1[0])
print(txt1[[0, 1]])

# get cols
print(txt1[:, 2:])

print(txt1[0:2, 1:3])

# get point
print(txt1[[0, 0, 0], [0, 1, 2]])
print(txt1[0, 0])

print(txt1 < 10)
txt1[txt1 < 5] = 6
print(txt1)

print('*' * 50)

txt2 = np.loadtxt('1.csv', dtype=int, skiprows=1, delimiter=',', unpack=True)
print(txt2)

print(np.where(txt2 < 5, 6, 10))

# replace number which less than 5 to s and larger than 6 to 6
print(txt2.clip(5, 6))
