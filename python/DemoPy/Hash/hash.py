'''
Created on Jul 1, 2018

@author: Administrator
'''

'''
key = [1, 2, 3, 4, 5]
value = ['a', 'b', 'c', 'd', 'e']
key_value = {1:'a', 2:'b', 3:'d', 4:'e', 5:'f'}
print(key_value[1])

dict4 = dict(luo='haha', wei='hahaha')
print(dict4)
dict5 = dict((('luo', 'haha'), ('wei', 'hahaha')))
print(dict5)
dict6 = {}
dict6 = dict6.fromkeys((1, 2, 3), ('one', 'two', 'three'))
print(dict6)
for each in dict6.keys():
    print(each)
for item in dict6.items():
    print(item)
print(dict6.get(3))
print(5 in dict6)
key_value.clear()
print(key_value)
dict7 = dict4.copy()
dict8 = dict4
dict4.popitem()
print(dict7, dict8, dict4)
dict4.setdefault('biao', 'hahahaha')
print(dict4)
b = {'lwb':'shuai'}
dict4.update(b)
print(dict4)
'''

set1 = {1, 2, 3, 4, 5}
print(set1)
set2 = set([1, 2 ,2 ,3 ,3 ,5])
print(set2)
