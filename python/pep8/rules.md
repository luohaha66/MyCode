# Python Code Rules

## Code Lay-out

```bash
# Yes

# Aligned with opening delimiter.
foo = long_function_name(var_one, var_two,
                         var_three, var_four)

# More indentation included to distinguish this from the rest.
def long_function_name(
        var_one, var_two, var_three,
        var_four):
    print(var_one)

# Hanging indents should add a level.
foo = long_function_name(
    var_one, var_two,
    var_three, var_four)

# No

# Arguments on first line forbidden when not using vertical alignment.
foo = long_function_name(var_one, var_two,
    var_three, var_four)

# Further indentation required as indentation is not distinguishable.
def long_function_name(
    var_one, var_two, var_three,
    var_four):
    print(var_one)

# No extra indentation.
if (this_is_one_thing and
    that_is_another_thing):
    do_something()
```

## Should a Line Break Before or After a Binary Operator?

```bash
## No: operators sit far away from their operands
income = (gross_wages +
          taxable_interest +
          (dividends - qualified_dividends) -
          ira_deduction -
          student_loan_interest)

## Yes: easy to match operators with operands
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
```

## Source File Encoding

- Code in the core Python distribution should always use UTF-8 (or ASCII in Python 2).
- Files using ASCII (in Python 2) or UTF-8 (in Python 3) should not have an encoding declaration

## Imports

- Yes: import os
- import sys
- from subprocess import Popen, PIPE
- No:  import sys, os
- imports should be grouped in the following order:
  - Standard library imports.
  - Related third party imports.
  - Local application/library specific imports.
  - You should put a blank line between each group of imports. 
- Absolute imports are recommended
  - import mypkg.sibling
  - from mypkg import sibling
  - from mypkg.sibling import example
- Wildcard imports (from `<module>` import *) should be avoided

## Module Level Dunder Names

- Module level "dunders" (i.e. names with two leading and two trailing underscores) such as __all__, __author__, __version__, etc. should be placed after the module docstring but before any import statements except from __future__ imports. Python mandates that future-imports must appear in the module before any other code except docstrings:

```bash
"""This is the example module.

This module does stuff.
"""

from __future__ import barry_as_FLUFL

__all__ = ['a', 'b', 'c']
__version__ = '0.1'
__author__ = 'Cardinal Biggles'

import os
import sys
```

## Other Recommendations

```bash
Yes:
i = i + 1
submitted += 1
x = x*2 - 1
hypot2 = x*x + y*y
c = (a+b) * (a-b)

No:
i=i+1
submitted +=1
x = x * 2 - 1
hypot2 = x * x + y * y
c = (a + b) * (a - b)

Yes:
def complex(real, imag=0.0):
    return magic(r=real, i=imag)
No:
def complex(real, imag = 0.0):
    return magic(r = real, i = imag)

# Function annotations should use the normal rules
# for colons and always have spaces around the -> arrow if present
Yes:
def munge(input: AnyStr): ...
def munge() -> AnyStr: ...

No:
def munge(input:AnyStr): ...
def munge()->PosInt: ...

# When combining an argument annotation with a default value,
# use spaces around the = sign (but only for those arguments
# that have both an annotation and a default).
Yes:
def munge(sep: AnyStr = None): ...
def munge(input: AnyStr, sep: AnyStr = None, limit=1000): ...

No:
def munge(input: AnyStr=None): ...
def munge(input: AnyStr, limit = 1000): ...
```

## Package and Module Names

- Modules should have short, all-lowercase names. Underscores can be used in the module name if it improves readability. Python packages should also have short, all-lowercase names, although the use of underscores is discouraged.
- When an extension module written in C or C++ has an accompanying Python module that provides a higher level (e.g. more object oriented) interface, the C/C++ module has a leading underscore (e.g. _socket).

## Class Names

- Class names should normally use the CapWords convention.

## Type Variable Names

- Names of type variables introduced in PEP 484 should normally use CapWords preferring short names: T, AnyStr, Num. It is recommended to add suffixes _co or _contra to the variables used to declare covariant or contravariant behavior correspondingly

## Function and Variable Names

- Function names should be lowercase, with words separated by underscores as necessary to improve readability.

## Method Names and Instance Variables

- Use one leading underscore only for non-public methods and instance variables.

## Public and Internal Interfaces

- To better support introspection, modules should explicitly declare the names in their public API using the __all__ attribute. Setting __all__ to an empty list indicates that the module has no public API.
- Even with __all__ set appropriately, internal interfaces (packages, modules, classes, functions, attributes or other names) should still be prefixed with a single leading underscore.
- __function defined in class will be change to _classname__function

```bash
object  # public
__object__  # special, python system use, user should not define like it
__object  # private (name mangling during runtime)
          # 类中的私有变量名,子类对象不能访问
_object  # obey python coding convention, consider it as private
         # 保护变量，意思是只有类对象和子类对象能够访问到这些变量(尽量避免在类外部直接修改)

class Foo():

    def __init__():
        ...

    def public_method():
        print 'This is public method'

    def __fullprivate_method(): # _Foo____fullprivate_method
        print 'This is double underscore leading method'

    def _halfprivate_method():
        print 'This is one underscore leading method'

f = Foo()
f.public_method()  # OK
f.__fullprivate_method()  # Error occur
f._halfprivate_method()  # OK
f._Foo__fullprivate()_method()  # OK
```

## Recommend

- Be consistent in return statements. Either all return statements in a function should return an expression, or none of them should. If any return statement returns an expression, any return statements where no value is returned should explicitly state this as return None, and an explicit return statement should be present at the end of the function (if reachable).

```bash
Yes:
def foo(x):
    if x >= 0:
        return math.sqrt(x)
    else:
        return None

def bar(x):
    if x < 0:
        return None
    return math.sqrt(x)

No:
def foo(x):
    if x >= 0:
        return math.sqrt(x)

def bar(x):
    if x < 0:
        return
    return math.sqrt(x)
```

- Use string methods instead of the string module. String methods are always much faster and share the same API with unicode strings. Override this rule if backwards compatibility with Pythons older than 2.0 is required.

```bash
Yes: if foo.startswith('bar'):
No:  if foo[:3] == 'bar':
```

- Object type comparisons should always use isinstance() instead of comparing types directly.

```bash
Yes: if isinstance(obj, int):

No:  if type(obj) is type(1):
```

- For sequences, (strings, lists, tuples), use the fact that empty sequences are false.

```bash
Yes: if not seq:
     if seq:

No:  if len(seq):
     if not len(seq):
```

- Don't compare boolean values to True or False using ==

```bash
Yes:   if greeting:
No:    if greeting == True:
Worse: if greeting is True:
```