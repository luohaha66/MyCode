'''
Created on Sep 10, 2018

@author: Administrator
'''


class Singleton(object):

    # method used for instantiation object
    def __new__(cls):
        if not hasattr(cls, 'instance'):
            cls.instance = super(Singleton, cls).__new__(cls)
        return cls.instance

    
class LazySingleton(object):
    __instance = None

    def __init__(self):
        if not LazySingleton.__instance:
            print('__init__ method called')
        else:
            print('instance already created', self.getInstance())
    
    @classmethod
    def getInstance(cls):
        if not cls.__instance:
            cls.__instance = LazySingleton()
        return cls.__instance


class Monostate(object):
    __shared_state = {}
#     def __init__(self):
#         self.x = 1                                                                       
#         # all object's status saved in __dict__ 
#         self.__dict__ = self.__shared_state
    
    # or like this
    def __new__(cls, *args, **kwargs):
        obj = super(Monostate, cls).__new__(cls, *args, **kwargs)
        obj.x = 1
        obj.__dict__ = cls.__shared_state
        return obj

        
if __name__ == '__main__':
    # designMode
    s = Singleton()
    print(s)
    s1 = Singleton()
    print(s1)
    
    # class initialized, but object not create  
    s = LazySingleton()
    print(s)
    print("object created", LazySingleton.getInstance())
    s1 = LazySingleton()
    print(s, s1)
    
    # _Monostate
    s = Monostate()
    s1 = Monostate()
    s1.x = 4
    print(s, s.__dict__)
    print(s1, s1.__dict__)
    
    
