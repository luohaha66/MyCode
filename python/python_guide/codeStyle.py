"""
1. When a function has more than two or three positional parameters, its signature is more
difficult to remember and using keyword arguments with default values is helpful.
2. *args: list, **kwargs: dictionary
"""


class ExplicitCode:

    # bad
    @staticmethod
    def make_complex(*args):
        x, y = args
        return dict(**locals())

    # good
    @staticmethod
    def make_complex1(x, y):
        return {'x': x, 'y': y}


class ReturnValue:

    @staticmethod
    def complex_function(a, b, c):
        if not a:
            return None  # Raising an exception might be better
        if not b:
            return None  # Raising an exception might be better
        # Some complex code trying to compute x from a, b and c
        x = a + b + c
        # Resist temptation to return x if succeeded
        if not x:
            # Some Plan-B computation of x
            x = a
        return x  # One single exit point for the returned value x will help when maintaining the code.


class Idiom:
    @staticmethod
    def un_pack():
        # enumerate() will provide a tuple of two elements for each item in list
        n_list = [0, 1, 2, 3, 4, 5, 6]
        a, b = 1, 2
        for index, item in enumerate(n_list):
            print(index, item)
        # use this to swap variables
        a, b = b, a
        print(a, b)
        a, (b, c) = 4, (5, 6)
        print(a, b, c)
        # In Python 3, a new method of extended unpacking was introduced by PEP 3132:
        a, *rest = [1, 2, 3]
        # a = 1, rest = [2, 3]
        print(a, rest)
        a, *middle, c = [1, 2, 3, 4]
        # a = 1, middle = [2, 3], c = 4
        print(a, middle, c)


# Create an ignored variable
def create_ignored():
    filename = 'foobar.txt'
    basename, __, ext = filename.rpartition('.')
    print(basename, ext)


def create_something():
    # Create a length-N list of the same thing
    l_num = [1, 2] * 4
    print(l_num)
    # Create a length-N list of lists
    l_num_1 = [[1, 2] for __ in range(4)]
    print(l_num_1)
    # Create a string from a list
    love = ['l', 'o', 'v', 'e']
    love_s = ''.join(love)  # better method
    print(love_s)


def search_in_collection():
    s = {'s', 'p', 'a', 'm'}
    l = ['s', 'p', 'a', 'm']
    print('s' in s)  # hash_tables, search quickly,
    # Searching in dictionaries works the same way, need more memory
    print('s' in l)  # search slowly


if __name__ == '__main__':
    # print(ExplicitCode.make_complex(1, 2))
    # print(ExplicitCode.make_complex1(3, 4))
    Idiom.un_pack()
    # create_ignored()
    # create_something()
    # search_in_collection()


