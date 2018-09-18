'''
Created on Jul 8, 2018

@author: Administrator
'''

class Pro:
    def __init__(self, value = 26):
        self.value = float(value)
        
#     def __setattr__(self, name ,value):
#         print('setattr')
#         
#     def __getattr__(self, name):
#         print('getattr')
#     
#     def __getattribute__(self, name):
#         print('getattribute')
#         
#     def __delattr__(self):
#         print('delattr')
    
    def __get__(self, instance, owner):
        print('p1 getting')
        return self.value
    
    def __set__(self, instance, value):
        print('p1 setting')
        self.value = float(value)
        
    def __delete__(self, instance):
        print('deleting')
    
class Pro1:
    def __set__(self, instance, value):
        print('p2 setting')
        instance.p = float(value) + 100
    
    def __get__(self, instance, owner):
        print('p2 getting')
        return instance.p - 100
    
class Pro2:
    p = Pro()
    p1 = Pro1()

# p2 = Pro2()
# print(p2.p)
# p2.p = 30
# print(p2.p1)
# p2.p1 = 200
# print(p2.p)

a=1
b=2
c=3
a,b,c=b,a+b,a+b+c
print(a)
print(b)
print(c)


