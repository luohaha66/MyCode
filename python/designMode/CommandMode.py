'''
Created on Sep 13, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract
from abc import ABCMeta, abstractmethod

# abstract class of command
class Order(metaclass = ABCMeta):
    @abstractmethod
    def execute(self):
        pass

# ConcreteCommand
class BuyStockOrder(Order):
    def __init__(self, stock):
        self.stock = stock
    
    def execute(self):
        self.stock.buy()

# ConcreteCommand
class SellStockOrder(Order):
    def __init__(self, stock):
        self.stock = stock
    
    def execute(self):
        self.stock.sell()

# command receiver
class StockTrade():
    def buy(self):
        print('buy stock')
        
    def sell(self):
        print('sell stock')

# stock agent
class Agent(object):
    def __init__(self): 
        self.__orderQueue = []
        
    def placeOrder(self, order):
        self.__orderQueue.append(order)
        order.execute()          
        

if __name__ == '__main__':
    # command
    stock = StockTrade()
    buyCommand = BuyStockOrder(stock)
    sellCommand = SellStockOrder(stock)
    
    # agent
    agent = Agent()
    agent.placeOrder(buyCommand)
    agent.placeOrder(sellCommand)