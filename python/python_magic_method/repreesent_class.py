"""
 In Python, there’s a few methods
that you can implement in your class definition to customize how built in functions that return
representations of your class behave
__str__(self) Defines behavior for when str() is called on an instance of your class.
__repr__(self) Defines behavior for when repr() is called on an instance of your class. The
major difference between str() and repr() is intended audience. repr() is intended to
produce output that is mostly machine-readable (in many cases, it could be valid Python
code even), whereas str() is intended to be human-readable.
__unicode__(self) Defines behavior for when unicode() is called on an instance of your class.
unicode() is like str(), but it returns a unicode string. Be wary: if a client calls str()
on an instance of your class and you’ve only defined __unicode__(), it won’t work. You
should always try to define __str__() as well in case someone doesn’t have the luxury of
using unicode.
__format__(self, formatstr) Defines behavior for when an instance of your class is used in
new-style string formatting. For instance, "Hello, 0:abc!".format(a) would lead to
the call a.__format__("abc"). This can be useful for defining your own numerical or
string types that you might like to give special formatting options.
__hash__(self) Defines behavior for when hash() is called on an instance of your class. It
has to return an integer, and its result is used for quick key comparison in dictionaries.
Note that this usually entails implementing __eq__ as well. Live by the following rule: a
== b implies hash(a) == hash(b).
__nonzero__(self) Defines behavior for when bool() is called on an instance of your class.
Should return True or False, depending on whether you would want to consider the instance to be True or False.
__dir__(self) : Defines behavior for when dir() is called on an instance of your class. This
method should return a list of attributes for the user. Typically, implementing __dir_-
_ is unnecessary, but it can be vitally important for interactive use of your classes if you
redefine __getattr__ or __getattribute__ (which you will see in the next section) or
are otherwise dynamically generating attributes.
7
"""


class RepDemo:
    def __init__(self, value=''):
        self.value = value
        pass

    def __str__(self):
        return self.value


if __name__ == '__main__':
    d = RepDemo('hello world')
    print(str(d))
