'''
Created on Sep 13, 2018

@author: Administrator
'''

# sub system
class Hotelier(object):
    def __init__(self):
        print('hello, i am the hotelier')
    
    def book(self):
        print('registered the booking')

# sub system        
class Florist(object):
    def __init__(self):
        print('hello, i am the florist')
    
    def prepare(self):
        print('flowers is preparing')

# sub system
class Musician(object):
    def __init__(self):
        print('hello, i am the musician')
    
    def play(self):
        print('musician is read for playing')

# Facade
class FacadeCenter(object):
    def __init__(self):
        print('hello. i am the facade center')
    
    def arrange(self):
        self.hotelier = Hotelier()
        self.hotelier.book()
        
        self.florist = Florist()
        self.florist.prepare()
        
        self.musician = Musician()
        self.musician.play()
        
# my, control everything
class My(object):
    def __init__(self):
        print('i am the gold')
        
    def askFacadeCenter(self):
        print('let me contract with the facade center')
        self.fc = FacadeCenter()
        self.fc.arrange()   

if __name__ == '__main__':
    my = My()
    my.askFacadeCenter()
    