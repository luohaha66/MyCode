'''
Created on Jul 7, 2018

@author: Administrator
'''

class Woman(list):
    __sex = 100
    __height = 175
    __weight = 90
    
    def __init__(self, sex = 100, height = 175, weight = 90):
        self.__sex = sex
        self.__height = height
        self.__weight = weight
      
    def getPro(self):
        return self.__height, self.__weight, self.__sex
    
    def setPro(self, height, weight = 130, sex = 200):
        self.__height = height
        self.__weight = weight
        self.__sex = sex
    
    def delPro(self):
        pass
    
    op = property(getPro, setPro, delPro)

print(Woman._Woman__sex)
woman = Woman()
print(woman.op)
woman.op = 180
print(woman._Woman__sex, woman._Woman__height)
print(woman.op)
del woman.op       

class A:
    def info(self):
        print('I am A')

class B(A):
    __x = 0
    def info(self, x = 0):
        super().info()
        self.x = x
        print('I am b')

C = B()
C.info()
print(issubclass(B, A))
print(issubclass(A, object))
print(isinstance(C, B))
print(isinstance(C, A))
print(hasattr(woman, '__sex'))
print(hasattr(C, 'x'))
print(getattr(C, 'x', '-EVALID'))
setattr(C, 'x', 100)
print(getattr(C, 'x', '-EVALID'))
