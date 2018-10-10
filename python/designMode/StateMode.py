'''
Created on Sep 14, 2018

@author: Administrator
'''

class ComputerState(object):
    name = 'state'
    allowed = []
    
    def switch(self, state):
        if state.name in self.allowed:
            print('Current state', self, '=> switch to mew state', state.name)
            self.__class__ = state
        else:
            print('Current state', self, '=> can not switch to mew state', state.name)
    
    def __str__(self):
        return self.name
    
class On(ComputerState):
    name = 'on'
    allowed = ['off', 'sleep']

class Off(ComputerState):
    name = 'off'
    allowed = ['on']
    
class Sleep(ComputerState):
    name = 'sleep'
    allowed = ['on', 'off']

class Computer(object):
    def __init__(self, mode = 'HP'):
        self.mode = mode
        self.state = Off()
    
    def change(self, state):
        self.state.switch(state)           

if __name__ == '__main__':
    com = Computer()
    com.change(On)
    com.change(Sleep)
    com.change(Off)
    com.change(On)
    