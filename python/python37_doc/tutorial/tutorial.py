def for_else():
    # Loop statements may have an else clause; it is executed when the loop terminates through exhaustion of
    # the list (with for) or when the condition becomes false (with while), but not when the loop is terminated
    # by a break statement.
    for n in range(2, 10):
        for x in range(2, n):
            if n % x == 0:
                print(n, '=', x, '*', n // x)
                break
        else:
            print(n, 'is a prime number')


def arguments():
    # The default value is evaluated only once. This makes a difference when the default is
    # a mutable object such as a list, dictionary, or instances of most classes. For example, the following function
    # accumulates the arguments passed to it on subsequent calls:
    i = 5

    def f(arg=i):
        print(arg)
    f()
    i = 6
    f()

    def f(a, L=[]):
        L.append(a)
        return L
    print(f(1))
    print(f(2))
    print(f(3))


def func_doc():
    def concat(*args, sep="/"):
        return sep.join(args)

    print(concat("earth", "mars", "venus"))
    print('***'.join(['a', 'b', 'c', 'd']))

    def make_incrementor(n):
        """
        Do nothing, but document it.

        No, really, it doesn't do anything.
        :param n:
        :return:
        """
        return lambda x: x + n

    f = make_incrementor(42)
    print(f(1))
    print(make_incrementor.__doc__)

    def f(ham: str, eggs: str = 'eggs') -> str:
        print("Arguments:", ham, eggs)
        return ham + ' and ' + eggs

    print(f('spam'))
    print("Annotations:", f.__annotations__)


def list_demo():
    #  from collections import deque, fast queue
    squares = list(map(lambda x: x ** 2, range(10)))
    print(squares)
    squares = [x ** 2 for x in range(10)]
    print(squares)
    print([(x, y) for x in [1, 2, 3] for y in [3, 1, 4] if x != y])

    matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
    print(list(zip(*matrix)))


def tuple_demo():
    t = 12345, 54321, 'hello!'
    print(t[0])
    # Tuples may be nested:
    u = t, (1, 2, 3, 4, 5)
    print(u)
    singleton = 'hello',  # <-- note trailing comma
    print(singleton)


def set_demo():
    basket = {'apple', 'orange', 'apple', 'pear', 'orange', 'banana'}
    print(basket)
    a = set('abracadabra')
    b = set('alacazam')
    print(a)
    print(b)
    print(a - b)
    print(a | b)
    print(a & b)
    print(a ^ b)  # letters in a or b but not both


def dict_demo():
    print(dict([('sape', 4139), ('guido', 4127), ('jack', 4098)]))
    print(dict(sape=4139, guido=4127, jack=4098))


def loop_demo():
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


def format_out():
    year = 2016
    event = 'Referendum'
    print(f'Results of the {year} {event}')
    yes_votes = 42_572_654

    no_votes = 43_132_495
    percentage = yes_votes / (yes_votes + no_votes)
    print('{:-9} YES votes {:2.2%}'.format(yes_votes, percentage))

    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
    for name, phone in table.items():
        print(f'{name:10} ==> {phone:10d}')
    animals = 'eels'
    print(f'My hovercraft is full of {animals}.')
    print(f'My hovercraft is full of {animals!r}.')
    print('The story of {0}, {1}, and {other}.'.format('Bill', 'Manfred',
                                                       other='Georg'))
    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
    print('Jack: {0[Jack]:d}; Sjoerd: {0[Sjoerd]:d}; '
          'Dcab: {0[Dcab]:d}'.format(table))
    print('Jack: {Jack:d}; Sjoerd: {Sjoerd:d}; Dcab: {Dcab:d}'.format(**table))


def except_demo():
    import sys
    for arg in sys.argv[1:]:
        try:
            f = open(arg, 'r')
        except OSError:
            print('cannot open', arg)
        else:
            print(arg, 'has', len(f.readlines()), 'lines')
            f.close()


if __name__ == '__main__':
    format_out()
