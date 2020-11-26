# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_default _value.py
* CREATED TIME: 2020/4/8 0008 18:03
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    i = 5

    def f(arg=i):
        print(arg)

    i = 6
    f()  # will print 5

    # The default value is evaluated only once
    def f(a, L = []):
        L.append(a)
        return L

    print(f(1))
    print(f(2))
    print(f(3))
