'''
Created on Sep 13, 2018

@author: Administrator
'''

class Actor(object):
    def __init__(self):
        self.isbusy = False
        
    def occupied(self):
        self.isbusy = True
        print(type(self).__name__, 'is busy')
    
    def available(self):
        self.isbusy = False
        print(type(self).__name__, 'is available')
        
    def status(self):
        return self.isbusy    

class Agent(object):
    def __init__(self):
        self.principal = None
    
    def work(self):
        self.actor = Actor()
        if self.actor.status():
            self.actor.occupied()
        else:
            self.actor.available()

if __name__ == '__main__':
    agent = Agent()
    agent.work()