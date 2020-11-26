# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_ambda.py
* CREATED TIME: 2020/4/27 0027 10:38
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    def make_incrementor(n):
        return lambda x: x + n

    f = make_incrementor(42)
    print(f(0))
    print(f(1))

    pairs = [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]
    # a b c d... sort
    pairs.sort(key=lambda pair: pair[1])
    print(pairs)
