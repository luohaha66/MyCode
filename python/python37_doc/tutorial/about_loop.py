# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_loop.py
* CREATED TIME: 2020/5/1 0001 19:09
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    knights = {'gallahad': 'the pure', 'robin': 'the brave'}
    for k, v in knights.items():
        print(k, v)

    for i, v in enumerate(['tic', 'tac', 'toe']):
        print(i, v)

    questions = ['name', 'quest', 'favorite color']
    answers = ['lancelot', 'the holy grail', 'blue']
    for q, a in zip(questions, answers):
        print('What is your {0}? It is {1}.'.format(q, a))

    for i in reversed(range(1, 10, 2)):
        print(i)

    basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
    for f in sorted(set(basket)):
        print(f)

    # It is sometimes tempting to change a list while you are looping over it;
    # however, it is often simpler and safer to create a new list instead
    import math
    raw_data = [56.2, float('NaN'), 51.7, 55.3, 52.5, float('NaN'), 47.8]
    filtered_data = []
    for value in raw_data:
        if not math.isnan(value):
            filtered_data.append(value)
    print(filtered_data)

    string1, string2, string3 = '', 'Trondheim', 'Hammer Dance'
    non_null = string1 or string2 or string3
    print(non_null)
