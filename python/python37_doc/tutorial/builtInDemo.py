def t1():
    print(abs(-2.356))
    a = [1, False, None]
    print(all(a))
    print(any(a))

    print(bin(255))
    print(format(255, '#b'))
    print(f'{255:#b}')
    print(hex(255))
    print(oct(255))

    print(bool(5))
    print(bool(-10))
    print(bool(0))


def t2():
    print(bytearray('红红火火恍恍惚惚', 'utf-8'))
    print(bytearray(5))
    print(bytearray([0, 1, 2, 3]))

    print(bytes('红红火火恍恍惚惚', 'utf-8'))
    print(bytes(5))
    print(bytes([0, 1, 2, 3]))


def t3():
    print(callable(t2))
    print(chr(97))
    print(ord('a'))
    print(complex(1, 5) * 2)
    print(complex('2+3j'))
    print(divmod(10, 20))  # (a//b, a%b)

    print(list(enumerate(['a', 'b', 'c', 'd'])))
    # print(globals())
    print(locals())
    x = 2
    print(eval('x + 3'))


def mm(x):
    if x > 5:
        return x
    else:
        return None


def t4():
    # Note that filter(function, iterable) is equivalent to the generator expression (item for item
    # in iterable if function(item)) if function is not None and (item for item in iterable if
    # item) if function is None
    print(list(filter(mm, [1, 5, 2, 6, 7])))
    print(list(filter(None, [False, None, 1, 1, 2, 3])))

    print(float('+1.23'))
    print(float(' -12345\n'))
    print(float('1e-003'))
    print(float('+1E6'))
    print(float('-Infinity'))
    print(float('-nan'))
    print(float('+inf'))

    print(hash(float(5.0)))
    print(format(255, '#X'))
    print(id(t2))

    print(input('-->'))


class IntDemo(int):
    def __init__(self):
        super().__init__()


def nn(x):
    return x + 5


def t5():
    a = int()
    print(isinstance(a, int))
    print(issubclass(IntDemo, int))
    print(list(map(nn, [1, 2, 3, 4])))

    import locale
    print(locale.getpreferredencoding(False))
    print(list(range(0, 10, 2)))

    print(list(reversed([1, 2, 3, 4, 5])))
    print(round(1.5))


class C:
    # If c is an instance of C, c.x will invoke the getter, c.x = value will invoke the setter and del c.x
    # the deleter
    def __init__(self):
        self._x = None

    def getx(self):
        return self._x

    def setx(self, value):
        self._x = value

    def delx(self):
        del self._x

    x = property(getx, setx, delx, "I'm the 'x' property.")


class C1:
    def __init__(self):
        self._x = None

    @property
    def x(self):
        """I'm the 'x' property."""
        return self._x

    @x.setter
    def x(self, value):
        self._x = value

    @x.deleter
    def x(self):
        del self._x


def t6():
    x = [1, 2, 3]
    y = [4, 5, 6]
    zipped = zip(x, y)
    print(list(zipped))
    x2, y2 = zip(*zip(x, y))
    print(x == list(x2) and y == list(y2))


def t7():
    import math
    x = 5.1321321
    print(math.floor(x))
    print(math.ceil(x))
    y = 6
    print(y.bit_length())
    print((1024).to_bytes(8, byteorder='big'))
    print(int.from_bytes(b'\x00\x00\x00\x00\x00\x00\x04\x00', byteorder='big'))
    print(int.from_bytes([255, 0, 0], byteorder='big'))
    print((16711680).to_bytes(8, byteorder='big'))

    print(float.as_integer_ratio(1.5))
    print((1.5).is_integer())
    print(float.hex(1.5))
    print(float.fromhex('0x1.8000000000000p+0'))


def t8():
    # What has happened is that [[]] is a one-element list containing an empty list, so all three elements
    # of [[]] * 3 are references to this single empty list. Modifying any of the elements of lists modifies
    # this single list
    lists = [[]] * 3
    print(lists)
    lists[0].append(1)
    print(lists[0])
    print(lists[1])
    print(lists)

    # You can create a list of different lists this way
    lists = [[] for i in range(3)]
    print(lists)
    lists[0].append(3)
    lists[1].append(5)
    lists[2].append(7)
    print(lists)


if __name__ == '__main__':
    t4()
    # print(dir())
    # numpy = __import__('numpy', globals(), locals(), [], 0)
    # print(numpy.array([1, 2, 3]))
    # t8()
