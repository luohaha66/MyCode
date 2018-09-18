'''
Created on Jul 7, 2018

@author: Administrator
'''

list = [1, 2, 3, 4, 5]

try:
    print(list[4])
    try:
        open('abcd.txt', 'r')
    except Exception as reason:
        print(str(reason))
except Exception as reason:
        print(str(reason))
else:
    print('no excep')
finally:
    print('excep final')