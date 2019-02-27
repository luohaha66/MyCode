"""
we cover the typical binary operators (and a function or two): +, -, * and the like. These
are, for the most part, pretty self-explanatory.
__add__(self, other) Implements addition.
__sub__(self, other) Implements subtraction.
__mul__(self, other) Implements multiplication.
__floordiv__(self, other) Implements integer division using the // operator.
__div__(self, other) Implements division using the / operator.
__truediv__(self, other) Implements true division. Note that this only works when from
__future__ import division is in effect.
__mod__(self, other) Implements modulo using the % operator.
__divmod__(self, other) Implements behavior for long division using the divmod() built in
function.
__pow__ Implements behavior for exponents using the ** operator.
__lshift__(self, other) Implements left bitwise shift using the << operator.
__rshift__(self, other) Implements right bitwise shift using the >> operator.
__and__(self, other) Implements bitwise and using the & operator.
__or__(self, other) Implements bitwise or using the | operator.
__xor__(self, other) Implements bitwise xor using the ^ operator.

You know how I said I would get to reflected arithmetic in a bit? Some of you might think it’s
some big, scary, foreign concept. It’s actually quite simple. Here’s an example:
some_object + other
That was "normal" addition. The reflected equivalent is the same thing, except with the
operands switched around:
other + some_object
For instance, in the example, some_object.__radd__ will only be called if ‘other‘ does not define
__add__.
__radd__(self, other) Implements reflected addition.
__rsub__(self, other) Implements reflected subtraction.
__rmul__(self, other) Implements reflected multiplication.
__rfloordiv__(self, other) Implements reflected integer division using the // operator.
__rdiv__(self, other) Implements reflected division using the / operator.
__rtruediv__(self, other) Implements reflected true division. Note that this only works
when from __future__ import division is in effect.
__rmod__(self, other) Implements reflected modulo using the % operator.
__rdivmod__(self, other) Implements behavior for long division using the divmod() built
in function, when divmod(other, self) is called.
__rpow__ Implements behavior for reflected exponents using the ** operator.
__rlshift__(self, other) Implements reflected left bitwise shift using the << operator.
__rrshift__(self, other) Implements reflected right bitwise shift using the >> operator.
__rand__(self, other) Implements reflected bitwise and using the & operator.
__ror__(self, other) Implements reflected bitwise or using the | operator.
__rxor__(self, other) Implements reflected bitwise xor using the ^ operator.

Python also has a wide variety of magic methods to allow custom behavior to be defined
for augmented assignment. You’re probably already familiar with augmented assignment, it
combines \normal" operators with assignment. If you still don’t know what I’m talking about,
here’s an example:
x = 5
x += 1 # in other words x = x + 1
Each of these methods should return the value that the variable on the left hand side should
be assigned to (for instance, for a += b, __iadd__ might return a + b, which would be assigned
to a). Here’s the list:
__iadd__(self, other) Implements addition with assignment.
__isub__(self, other) Implements subtraction with assignment.
__imul__(self, other) Implements multiplication with assignment.
__ifloordiv__(self, other) Implements integer division with assignment using the //= operator.
__idiv__(self, other) Implements division with assignment using the /= operator.
__itruediv__(self, other) Implements true division with assignment. Note that this only
works when from __future__ import division is in effect.
__imod__(self, other) Implements modulo with assignment using the %= operator.
__ipow__ Implements behavior for exponents with assignment using the **= operator.
__ilshift__(self, other) Implements left bitwise shift with assignment using the <<= operator.
__irshift__(self, other) Implements right bitwise shift with assignment using the >>= operator.
__iand__(self, other) Implements bitwise and with assignment using the &= operator.
__ior__(self, other) Implements bitwise or with assignment using the |= operator.
__ixor__(self, other) Implements bitwise xor with assignment using the ^= operator.
"""


class NormalDemo:
    def __init__(self, value=0):
        self.value = value
        pass

    def __add__(self, other):
        return self.value + other

    def __sub__(self, other):
        return self.value - other


if __name__ == '__main__':
    a = NormalDemo(5)
    print(a + 5)
    print(a - 4)
