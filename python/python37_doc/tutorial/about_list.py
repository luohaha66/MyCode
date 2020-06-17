# -*- coding: utf-8 -*-
"""
******************************************************************************
*                                 VIZVISION
*-----------------------------------------------------------------------------
* FILENAME: about_list.py
* CREATED TIME: 2020/4/8 0008 17:31
* AUTHOR: luoWB
* BRIEF:
******************************************************************************
"""

if __name__ == '__main__':
    a = [1, 2, 3]
    b = a[:]  # shadow copy from a
    print(a == b)
    print(a is b)
    b[0] = 0
    print(a)
    print(b)
    print(a == b)

    # replace some values
    b[1:] = [5, 5]
    print(b)
    # now remove
    b[1:] = []
    print(b)
    # clear b
    b[:] = []
    print(b)

    fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
    print(fruits.count('apple'))
    print(fruits.count('tangerine'))
    print(fruits.index('banana'))
    print(fruits.index('banana'), 4)  # Find next banana starting a position 4
    fruits.reverse()
    print(fruits)
    fruits.append('grape')
    print(fruits)
    fruits.sort()
    print(fruits)
    print(fruits.pop())

    from collections import deque

    queue = deque(["Eric", "John", "Michael"])
    queue.append("Terry")  # Terry arrives
    queue.append("Graham")  # Graham arrives
    print(queue)
    queue.popleft()  # The first to arrive now leaves
    print(queue)
    queue.popleft()
    print(queue)
    queue.pop()
    print(queue)

    a = [(x, y) for x in [1, 2, 3] for y in [3, 1, 4] if x != y]
    print(a)
    # equal to
    combs = []
    for x in [1, 2, 3]:
        for y in [3, 1, 4]:
            if x != y:
                combs.append((x, y))
    print(combs)

    vec = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    a = [num for elem in vec for num in elem]
    print(a)

    from math import pi
    a = [str(round(pi, i)) for i in range(1, 6)]
    print(a)

    matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
    ]
    a = [[row[i] for row in matrix] for i in range(4)]
    print(a)
    # In the real world, you should prefer built-in functions to complex flow statements.
    # The zip() function would do a great job for this use case
    a = list(zip(*matrix))
    print(a)
