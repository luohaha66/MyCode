# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_str_fmt.py
* CREATED TIME: 2020/5/14 0014 15:07
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    yes_votes = 42_572_654
    no_votes = 43_132_495
    a = 5_6.25
    percentage = yes_votes / (yes_votes + no_votes)
    print(a)
    print('{:-9} YES votes {:2.2%}'.format(yes_votes, percentage))

    import math

    print(f'The value of pi is approximately {math.pi:.3f}.')
    print('The value of pi is approximately %.3f.' % math.pi)

    # Passing an integer after the ':' will cause that field to be a minimum number of characters wide.
    # This is useful for making columns line up
    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
    for name, phone in table.items():
        print(f'{name:10}==>{phone:10d}')

    # Other modifiers can be used to convert the value before it is formatted. '!a' applies ascii(),
    # '!s' applies str(), and '!r' applies repr()
    animals = 'eels'
    print(f'My hovercraft is full of {animals!s}.')
    print(f'My hovercraft is full of {animals!r}.')
    print(f'My hovercraft is full of {animals!a}.')

    print('We are the {} who say "{}!"'.format('knights', 'Ni'))
    print('{1} and {0}'.format('spam', 'eggs'))
    print('This {food} is {adjective}.'.format(food='spam', adjective='absolutely horrible'))
    print('The story of {0}, {1}, and {other}.'.format('Bill', 'Manfred', other='Georg'))

    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
    print('Jack: {0[Jack]:d}; Sjoerd: {0[Sjoerd]:d}; Dcab: {0[Dcab]:d}'.format(table))
    print('Jack: {Jack:d}; Sjoerd: {Sjoerd:d}; Dcab: {Dcab:d}'.format(**table))

    for x in range(1, 11):
        print('{0:2d} {1:3d} {2:4d}'.format(x, x * x, x * x * x))

    a = '1111'
    print(a.rjust(10))
    print(a.ljust(10))
    print(a.center(10))
    print(a.zfill(10))
