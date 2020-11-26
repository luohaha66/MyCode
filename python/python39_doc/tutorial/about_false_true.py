# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_false_true.py
* CREATED TIME: 2020/4/8 0008 17:39
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    a = 0
    print(a is False)
    print(a == False)
    if not a:
        print('a is zero')

    a = 1
    print(a is True)
    print(a == True)
    if a:
        print('a is one')

    a = []
    print(a is False)
    print(a == False)
    print(a == [])
    print(a is [])
    if not a:
        print('a is empty list')
    a = ''
    print(a is False)
    print(a == False)
    print(a == '')
    print(a is '')
    if not a:
        print('a is empty str')
    a = {}
    print(a is False)
    print(a == False)
    print(a == {})
    print(a is {})
    if not a:
        print('a is empty dict')
