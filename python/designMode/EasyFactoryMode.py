'''
Created on Sep 11, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract,
from abc import ABCMeta, abstractmethod


class Animal(metaclass=ABCMeta):

    @abstractmethod
    def do_say(self):
        pass

    
class Dog(Animal):

    def do_say(self):
        Animal.do_say(self)
        print('wang wang wang')


class Cat(Animal):

    def do_say(self):
        Animal.do_say(self)
        print('miao miao miao')

        
# animal factory
class AnimalFactory(object):

    def make_sound(self, object_type):
        return eval(object_type)().do_say()


if __name__ == '__main__':
    f = AnimalFactory()
    f.make_sound('Dog')
    f.make_sound('Cat')
