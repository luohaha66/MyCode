def fib(n):
    if n == 0:
        return None
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


def fib1(n):
    if n == 0:
        return None
    if n == 1 or n == 2:
        return 1
    else:
        a = 1
        b = 1
        c = 0
        for i in range(2, n):
            c = a + b
            a = b
            b = c
        return c


if __name__ == '__main__':
    print(fib(1), fib(2), fib(3), fib(4), fib(5))
    print(fib1(1), fib1(2), fib1(3), fib1(4), fib1(5))
