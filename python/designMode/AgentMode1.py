'''
Created on Sep 13, 2018

@author: Administrator
'''
# ABCMeta is special metaClass of Python, used for creating class Abstract,
from abc import ABCMeta, abstractmethod

class Payment(metaclass = ABCMeta):
    @abstractmethod
    def do_pay(self):
        pass
    
# the real pay company
class ALIBaBa(Payment):
    def __init__(self):
        self.user = None
        
    def __getAccount(self):
        self.account = self.user
        return self.account
    
    def __hasFunds(self):
        print('ALiBaBa: checking if', self.__getAccount(), 'has enough money')
        return True
    
    def set_user(self, user):
        self.user = user
        
    def do_pay(self):
        if self.__hasFunds():
            print('ALiBaBa: pay success')
            return True
        else:
            print('ALiBaBa: not enough money')
            return False

# the agent
class Alipay(Payment):
    def __init__(self):
        self.alibaba = ALIBaBa()
    
    def do_pay(self):
        user = input('Proxy: please input user name: ')
        self.alibaba.set_user(user)
        return self.alibaba.do_pay()

class Me(object):
    def __init__(self):
        print('I want buy a car')
        self.alipay = Alipay()
        self.isPurchased = None
        
    def pay(self):
        self.isPurchased = self.alipay.do_pay()
        
    def __del__(self):
        if self.isPurchased:
            print('happy, i have a car :-)')
        else:
            print('sad, i can not afford it :(')    

if __name__ == '__main__':
    me = Me()
    me.pay()
    
    
    