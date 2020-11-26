# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_keyword_arg.py
* CREATED TIME: 2020/4/27 0027 10:22
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    def func(name, *args, **kwargs):
        print(name)
        print('*********')
        for arg in args:
            print(arg)
        print('############')
        for kw in kwargs:
            print(kw, ':', kwargs[kw])


    func("Limburger", "It's very runny, sir.",
         "It's really very, VERY runny, sir.",
         shopkeeper="Michael Palin",
         client="John Cleese",
         sketch="Cheese Shop Sketch")

    # unpack
    args = [3, 6]
    print(list(range(*args)))


    def parrot(voltage, state='a stiff', action='voom'):
        print("-- This parrot wouldn't", action, end=' ')
        print("if you put", voltage, "volts through it.", end=' ')
        print("E's", state, "!")


    d = {"voltage": "four million", "state": "bleedin' demised", "action": "VOOM"}
    parrot(**d)
