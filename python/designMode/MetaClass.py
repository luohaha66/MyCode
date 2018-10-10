'''
Created on Sep 11, 2018

@author: Administrator
'''


# MetaInt is int's metaClass, when create a int object,
# the MeataInt's method __call__ will be called, metaClass
# will override __new__ and __init__ method.
class MetaInt(type):
    
    def __call__(cls, *args, **kwds):
        print('****my int****', args)
        return type.__call__(cls, *args, **kwds)


class int(metaclass=MetaInt):
    
    def __init__(self, x, y):
        self.x = x
        self.y = y


# use metaClass realize singleton mode
class MetaSingleton(type):
    _instance = {}
    
    def __call__(cls, *args, **kwargs):
        print('***MetaSingleton***')
        if cls not in cls._instance:
            cls._instance[cls] = super(MetaSingleton, cls).__call__(*args, **kwargs)
        return cls._instance[cls]


class Singleton(metaclass=MetaSingleton):
    pass


if __name__ == '__main__':
    i = int(4, 5)
    s = Singleton()
    s1 = Singleton()
    print(s, s1)
    
