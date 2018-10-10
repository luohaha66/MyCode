from functools import partial
from operator import mul


# Python’s default arguments are evaluated once when the function is defined, not each time the function is called
def append_to(element, to=[]):
    to.append(element)
    return to


# Python’s closures are late binding. This means that the values of variables used
# in closures are looked up at the time the inner function is called
# Sometimes you want your closures to behave this way. Late binding is good in lots of situations.
def create_multipliers():
    return [lambda x: i * x for i in range(5)]


def create_multipliers_equal():
    multipliers = []
    for i in range(5):
        def multiplier(x):
            return i * x
        multipliers.append(multiplier)
    return multipliers


def create_multipliers1():
    return [lambda x, i=i: i * x for i in range(5)]


def create_multipliers2():
    return [partial(mul, i) for i in range(5)]


if __name__ == '__main__':
    l = append_to(1)
    print(l)
    l1 = append_to(2)
    print(l1)
    for multi in create_multipliers():
        print(multi(1))
    for multi in create_multipliers1():
        print(multi(1))
    for multi in create_multipliers2():
        print(multi(1))
