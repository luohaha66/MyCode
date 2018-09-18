'''
Created on Jul 7, 2018

@author: Administrator
'''
import pickle

'''
list = [1, 2, 3, 'abcde', ('a', 'b')]
file = open('mypk.pkl', 'wb')
pickle.dump(list, file)
file.close()
'''

file = open('mypk.pkl', 'rb')
list = pickle.load(file)
print(list)

