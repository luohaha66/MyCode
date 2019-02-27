"""
Unary operators and functions only have one operand, e.g. negation, absolute value, etc.
__pos__(self) Implements behavior for unary positive (e.g. +some_object)
__neg__(self) Implements behavior for negation (e.g. -some_object)
__abs__(self) Implements behavior for the built in abs() function.
__invert__(self) Implements behavior for inversion using the ~ operator.
__round__(self, n) Implements behavior for the build in round() function. n is the number
of decimal places to round to.
__floor__(self) : Implements behavior for math.floor(), i.e., rounding down to the nearest
integer.
__ceil__(self) : Implements behavior for math.ceil(), i.e., rounding up to the nearest
integer.
__trunc__(self) : Implements behavior for math.trunc(), i.e., truncating to an integral.
"""


class UnaryDemo:
    def __init__(self):
        pass

    def __pos__(self):
        print('pos method called')

    def __neg__(self):
        print('neg method called')

    def __abs__(self):
        print('abs method called')

    def __invert__(self):
        print('invert method called')


if __name__ == '__main__':
    a = UnaryDemo()
    b = +a
    b = -a
    b = ~a
    b = abs(a)
