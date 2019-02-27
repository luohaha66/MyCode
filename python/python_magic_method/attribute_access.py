"""
__getattr__(self, name) You can define behavior for when a user attempts to access an
attribute that doesn’t exist (either at all or yet).
__setattr__(self, name, value) Unlike __getattr__, __setattr__ is an encapsulation solution. It allows you to define behavior for assignment to an attribute regardless of whether
or not that attribute exists, meaning you can define custom rules for any changes in the
values of attributes.
__delattr__(self, name) This is the exact same as __setattr__, but for deleting attributes
instead of setting them. The same precautions need to be taken as with __setattr__ as
well in order to prevent infinite recursion (calling del self.name in the implementation
of __delattr__ would cause infinite recursion).
def __setattr__ (self , name , value ):
self.name = value
# since every time an attribute is assigned , __setattr__ ()
# is called , this is recursion . So this really means
# self.__setattr__ (’ name ’, value ). Since the method keeps
# calling itself , the recursion goes on forever causing a crash
def __setattr__ (self , name , value ):
self . __dict__ [ name ] = value # assigning to the dict of names in the class
# define custom behavior here
"""


class AccessCounter(object):
    """
    A class that contains a value and implements an
    access counter . The counter increments each time the
    value is changed .
    """

    def __init__(self, val):
        super(AccessCounter, self).__setattr__('counter', 0)
        super(AccessCounter, self).__setattr__('value', val)

    def __setattr__(self, name, value):
        if name == 'value':
            super(AccessCounter, self).__setattr__('counter',
                                                   self.counter + 1)
        # Make this unconditional .
        # If you want to prevent other attributes to be set ,
        # raise AttributeError ( name )
        super(AccessCounter, self).__setattr__(name, value)

    def __delattr__(self, name):
        if name == 'value':
            super(AccessCounter, self).__setattr__('counter',
                                                   self.counter + 1)
        super(AccessCounter, self).__delattr__(name)


if __name__ == '__main__':
    test = AccessCounter(100)
    print(test.value, test.counter)
    test.value = 2
    test.value = 3
    print(test.counter)
