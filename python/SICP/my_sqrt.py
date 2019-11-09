def test(x, y):
    if good_enough(x, y):
        return x
    else:
        x1 = improve(x, y)
        if x1 == 0:
            return x1
        return test(x1, y)


def good_enough(x, y):
    if -0.0001 < y - x * x < 0.001:
        return True
    return False


def improve(x, y):
    return (x + y / x) / 2


def my_sqrt(y):
    x = 1
    if 0 == y:
        return y
    return test(x, y)


if __name__ == '__main__':
    a = 4
    print(my_sqrt(a))
