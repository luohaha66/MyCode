# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_string.py
* CREATED TIME: 2020/4/8 0008 17:03
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

def str_base():
    # The string is enclosed in double quotes if the string contains a single quote and no double quotes,
    # otherwise it is enclosed in single quotes
    print('i don\'t')  # use \' to escape the single quote...
    print("i don't")  # ...or use double quotes instead

    # If you don’t want characters prefaced by \ to be interpreted as special characters,
    # you can use raw strings by adding an r before the first quote
    print('c:\name')
    print(r'c:\name')

    # String literals can span multiple lines. One way is using triple-quotes: """...""" or '''...'''
    print("""\
    Usage: thingy [OPTIONS]
        -h Display this usage message
        -H hostname Hostname to connect to
        """)

    print(3 * 'un' + 'ium')
    # Two or more string literals (i.e. the ones enclosed between quotes)
    # next to each other are automatically concatenated
    a = 'py'  'thon'
    print(a)

    """
    +---+---+---+---+---+---+
    | P | y | t | h | o | n |
    +---+---+---+---+---+---+
    0   1   2   3   4   5   6
    -6 -5  -4  -3  -2  -1
    """
    b = 'word'
    print(b[0], b[-1])
    print(b[0:3])
    # out of range slice indexes are handled gracefully when used for slicing
    if not b[5:100]:
        print('empty str')
    print(b[5:100] is None)
    print(b[5:100] is False)
    print(b[-3:-1])
    print(b[-100:-3])
    # Python strings cannot be changed — they are immutable
    try:
        b[0] = 'a'
    except Exception as e:
        print(e)


if __name__ == '__main__':
    ...
