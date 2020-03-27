'''
Created on Jul 15, 2018

@author: Administrator
'''

# import Func.func as h

def numbers():
    a = 0
    b = 1
    while True:
        a, b = b, a + b
        yield a
        print('yield finish')

print(next(numbers()))
a = [i for i in range(50) if not (i % 2) and (i % 3)]
print(a)
b = {i : i % 2 == 0 for i in range(10)}
print(b)
c = {i for i in [1, 1, 2, 2, 3, 3, 5, 5]}
print(c)
e = (i for i in range(5))
print(next(e))
print(sum((i for i in range(10) if i % 2)))
# h.hanoi(2, 'x', 'y', 'z')