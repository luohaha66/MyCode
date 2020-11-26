# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_for.py
* CREATED TIME: 2020/4/8 0008 17:51
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    # Loop statements may have an else clause;
    # it is executed when the loop terminates through exhaustion of the iterable
    # (with for) or when the condition becomes false (with while),
    # but not when the loop is terminated by a break statement
    for i in range(10):
        if i == 11:
            break
    else:
        print('out of range 1')

    for i in range(10):
        if i == 9:
            break
    else:
        print('out of range 2')
