'''
Created on Sep 11, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract
from abc import ABCMeta, abstractmethod

# abstract class of factory
class PizzaFactory(metaclass = ABCMeta):
    @abstractmethod
    def createVegPizza(self):
        pass
    
    @abstractmethod
    def createNoVegPizza(self):
        pass

# concreteFactory
class USAPizzaFactory(PizzaFactory):
    
    def createVegPizza(self):
        return USAVegPizza()
    
    def createNoVegPizza(self):
        return USANoVegPizza()

# concreteFactory
class CHINAPizzaFactory(PizzaFactory):
    
    def createVegPizza(self):
        return CHINAVegPizza()
    
    def createNoVegPizza(self):
        return CHINANoVegPizza()
    
# abstract class of product
class VegPizza(metaclass = ABCMeta):
    @abstractmethod
    def prepare(self, VegPizza):
        pass
    
# abstract class of product    
class NoVegPizza(metaclass = ABCMeta):
    @abstractmethod
    def serve(self, VegPizza):
        pass

# concreteProduct
class USAVegPizza(VegPizza):
    
    def prepare(self):
        print('prepare: ', type(self).__name__)
        
# concreteProduct
class USANoVegPizza(NoVegPizza):
    
    def serve(self, VegPizza):
        print(type(self).__name__, ' is server with no vegetable', type(VegPizza).__name__)

# concreteProduct
class CHINAVegPizza(VegPizza):
    
    def prepare(self):
        print('prepare: ', type(self).__name__)
        
# concreteProduct
class CHINANoVegPizza(NoVegPizza):
    
    def serve(self, VegPizza):
        print(type(self).__name__, ' is server with no vegetable', type(VegPizza).__name__)

# Pizza store
class PizzaStote():
    def __init__(self):
        pass
    
    def makePizza(self):
        for factory in [USAPizzaFactory(), CHINAPizzaFactory()]:
            self.factory = factory
            self.noVegPizza = self.factory.createNoVegPizza()
            self.vegPizza = self.factory.createVegPizza()
            self.vegPizza.prepare()
            self.noVegPizza.serve(self.vegPizza)

if __name__ == '__main__':
    pizza = PizzaStote()
    pizza.makePizza()

