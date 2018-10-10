import unittest


def add(a, b):
    """
    Add two numbers and return the result.
    :param a:
    :param b:
    :return:
    """
    return a + b


class Test(unittest.TestCase):
    def test(self):
        self.assertEqual(add(1, 2), 3)


if __name__ == '__main__':
    Test().test()
