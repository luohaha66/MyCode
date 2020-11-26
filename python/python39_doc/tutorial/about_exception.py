# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_exception.py
* CREATED TIME: 2020/5/14 0014 16:58
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    def bool_return():
        try:
            print('aaaa')
            return True
        finally:
            print('bbbbb')
            return False

    print(bool_return())

    def try_return():
        try:
            for i in range(10):
                print('cccc')
                return 5
        finally:
            print('ddddd')
            return False

    print(try_return())

    def try_return1():
        try:
            for i in range(10):
                print('cccc')
                return 5
        finally:
            print('ddddd')

    print(try_return1())
