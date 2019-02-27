"""
Python also has an array of magic methods designed to implement behavior for built in type
conversion functions like float(). Here they are:
__int__(self) Implements type conversion to int.
__long__(self) Implements type conversion to long.
__float__(self) Implements type conversion to float.
__complex__(self) Implements type conversion to complex.
__oct__(self) Implements type conversion to octal.
6__hex__(self) Implements type conversion to hexadecimal.
__index__(self) Implements type conversion to an int when the object is used in a slice
expression. If you define a custom numeric type that might be used in slicing, you should
define __index__.
__trunc__(self) Called when math.trunc(self) is called. __trunc__ should return the
value of self truncated to an integral type (usually a long).
__coerce__(self, other) Method to implement mixed mode arithmetic. __coerce__ should
return None if type conversion is impossible. Otherwise, it should return a pair (2-tuple)
of self and other, manipulated to have the same type.
"""


class TypeDemo:
    def __init__(self, value='0'):
        self.value = value
        pass

    def __int__(self):
        print('int method called')
        return int(self.value)


if __name__ == '__main__':
    t = TypeDemo()
    int(t)
