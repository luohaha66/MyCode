def array_test():
    from array import array
    a = array('H', [4000, 10, 700, 22222])
    print(sum(a))
    print(a[1:3])
    print(a[0])
    print(a[1])


# The collections module provides a deque() object that is like a list with faster appends and pops from
# the left side but slower lookups in the middle
def deque_demo():
    from collections import deque
    d = deque(["task1", "task2", "task3"])
    d.append("task4")
    print("Handling", d.popleft())

    import bisect
    scores = [(100, 'perl'), (200, 'tcl'), (400, 'lua'), (500, 'python')]
    bisect.insort(scores, (300, 'ruby'))
    print(scores)


def heap_demo():
    from heapq import heapify, heappop, heappush
    data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
    heapify(data)  # rearrange the list into heap order
    print(data)
    heappush(data, -5)  # add a new entry
    print(data)
    print([heappop(data) for i in range(5)])  # fetch the three smallest entries


def decimal_demo():
    import decimal
    print(round(decimal.Decimal('0.70') * decimal.Decimal('1.05'), 2))
    print(round(.70 * 1.05, 2))

    print(decimal.Decimal('1.00') % decimal.Decimal('.10'))
    print(1.00 % .10)
    print(sum([decimal.Decimal('0.1')] * 10) == decimal.Decimal('1.0'))
    print(sum([0.1] * 10) == 1.0)

    decimal.getcontext().prec = 36
    print(decimal.Decimal(1) / decimal.Decimal(7))


if __name__ == '__main__':
    # deque_demo()
    # heap_demo()
    decimal_demo()
