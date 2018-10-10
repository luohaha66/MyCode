'''
Created on Sep 14, 2018

@author: Administrator
'''


# mode
class Mode(object):

    def logic(self):
        data = 'got'
        print('Mode')
        return data


# view
class View(object):

    def update(self, data):
        print('View: updating data: ', data)


# control
class Controller(object):

    def __init__(self):
        self.mode = Mode()
        self.view = View()
    
    def interFace(self):
        print('Controller:')
        data = self.mode.logic()
        self.view.update(data)


class Client(object):

    def __init__(self):
        self.control = Controller()
        self.control.interFace()        


if __name__ == '__main__':
    Client()
