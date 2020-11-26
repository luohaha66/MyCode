# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_sets.py
* CREATED TIME: 2020/4/29 0029 18:11
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    # Note: to create an empty set you have to use set(), not {}
    a = set('abracadabra')
    b = set('alacazam')
    print(a)
    print(b)
    print(a - b)  # letters in a but not in b
    print(a | b)  # letters in a or b or both
    print(a & b)  # letters in both a and b
    print(a ^ b)  # letters in a or b but not both

    # Similarly to list comprehensions, set comprehensions are also supported:
    a = {x for x in 'abracadabra' if x not in 'abc'}
    print(a)

    tel = {'jack': 4098, 'sape': 4139}
    print(list(tel))  # can get the keys
    print(dict([('sape', 4139), ('guido', 4127), ('jack', 4098)]))
    print(dict(sape=4139, guido=4127, jack=4098))
