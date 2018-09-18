'''
Created on Jul 1, 2018

@author: Administrator
'''

'''
def MyHelloWorld(a, b):
    print(a, b)
    return print('helloworld')

def Add(a = 0, b = 0):
    'a is para, b is para'
    global number
    number = 10
    return print(a + b)

def test(*params):
    a = str(params[0])
    for each in range(1, len(params), 1):
        a += str(params[each])
    print(a)
    return 'a, b,', 'c, d'

number = 5
print(number)
MyHelloWorld('luo',  'wei')
Add(1, 2)
Add(a = 'abc', b = 'def')
Add()
help(Add)
print(test(1, 2, 'adv', 3, 'def'))
print(number)
'''

'''
def fun1(x):
    z = 5
    def fun2(y):
        nonlocal z
        z *= z
        return x * y * z
    return fun2

print(fun1(5)(5))
print(list(filter(lambda x : x % 2, range(10))))
print(list(map(lambda x : x * 2, range(10))))
'''

def hanoi(n, x, y, z):
    if n == 1:
        print(x, '--->', z)
    else:
        hanoi(n - 1, x, z, y)
        print(x, '--->', z)
        hanoi(n - 1, y, x, z)


#if __name__ == 'Func.func':
if __name__ == '__main__':
    hanoi(3, 'x', 'y', 'z')




