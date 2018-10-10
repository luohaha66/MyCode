'''
Created on Sep 11, 2018

@author: Administrator
'''

# ABCMeta is special metaClass of Python, used for creating class Abstract
from abc import ABCMeta, abstractmethod


# abstract class of Product
class Section(metaclass=ABCMeta):

    @abstractmethod
    def describe(self):
        pass


# contreteProduct 
class UserSection(Section):

    def describe(self):
        print("**UserSection**")


# contreteProduct
class PwdSection(Section):

    def describe(self):
        print("**PwdSection**")


# contreteProduct
class PropertySection(Section):

    def describe(self):
        print("**PropertySection**")


# contreteProduct
class EmailSection(Section):

    def describe(self):
        print("**EmailSection**")        


# abstract class of Creator
class FactoryProfile(metaclass=ABCMeta):

    def __init__(self):
        self.sections = []
        self.createProfile()
    
    @abstractmethod
    def createProfile(self):
        pass
    
    def getSections(self):
        return self.sections
    
    def addSections(self, section):
        self.sections.append(section)

    
# concreteCreater
class QQ(FactoryProfile):

    def createProfile(self):
        self.addSections(UserSection())
        self.addSections(PwdSection())

        
# concreteCreater
class Alipay(FactoryProfile):

    def createProfile(self):
        self.addSections(PropertySection())
        self.addSections(EmailSection())     

    
if __name__ == '__main__':
    p = eval('QQ')()
    print('profile:', type(p).__name__)
    print('sections:', p.getSections())
    p = eval('Alipay')()
    print('profile:', type(p).__name__)
    print('sections:', p.getSections())
    
    pass
