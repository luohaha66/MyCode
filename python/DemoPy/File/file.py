'''
Created on Jul 1, 2018

@author: Administrator
'''
import random
import os
'''
fd = open('py.txt', 'a+')
fd.write('hello summer\n')
fd.close()
'''
def saveFile(fileName, data):
    with open(fileName, 'w') as fd:
        fd.writelines(data)
    #fd.close() for using with,not needed

def splitFile(fileName):
    with open(fileName, 'r') as fd:
        count = 1
        data = []
        for line in fd:
            if line[:4] != '====':
                data.append(line)
            else:
                name = str(count) + '.txt'
                saveFile(name,  data)
                count += 1
                data.clear()
        saveFile(str(count) + '.txt', data)
        #fd.close()

splitFile('py.txt')
'''
strs = 'abc:haha:haha:haha'
(left, right) = strs.split(':', 1)
print(left)
print(right)
print(random.randint(1, 10))
print(os.getcwd())
os.mkdir('../test')
'''

#os.system('cmd')
#print(os.path.basename(os.getcwd()))
#print(os.path.dirname(os.getcwd()))



