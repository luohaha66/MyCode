'''
Created on Sep 13, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract
from abc import ABCMeta, abstractmethod


# subject
class NewsPublisher(object):
    
    
    def __init__(self):
        self.__subscribers = []
        self.__lastNews = None
        
    def attach(self, subscriber):
        self.__subscribers.append(subscriber)
        
    def detach(self):
        return self.__subscribers.pop()
    
    def subscribers(self):
        return [type(x).__name__ for x in self.__subscribers]
    
    def notifySubscribers(self):
        for sub in self.__subscribers:
            sub.update()
    
    def addNews(self, news):
        self.__lastNews = news
        
    def getNews(self):
        return 'got news:', self.__lastNews


# abstract class of observers
class Subscriber(metaclass=ABCMeta):

    @abstractmethod
    def update(self):
        pass

    
# observer
class WeiXin(Subscriber):

    def __init__(self, publisher):
        self.publisher = publisher
        self.publisher.attach(self)
    
    def update(self):
        print(type(self).__name__, self.publisher.getNews())


# observer        
class QQ(Subscriber):

    def __init__(self, publisher):
        self.publisher = publisher
        self.publisher.attach(self)
    
    def update(self):
        print(type(self).__name__, self.publisher.getNews())

                
if __name__ == '__main__':
    np = NewsPublisher()
    for sub in [WeiXin, QQ]:
        sub(np)
    print(np.subscribers())
    
    np.addNews('hello')
    np.notifySubscribers()
    
    print(type(np.detach()).__name__)
    print(np.subscribers())
    
    np.addNews('haha')
    np.notifySubscribers()
    pass
