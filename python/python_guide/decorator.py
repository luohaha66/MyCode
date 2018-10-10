from functools import wraps


def memo(fn):
    print('memo called')
    cache = {}
    miss = object()

    @wraps(fn)
    def wrapper(*args):
        print('wrapper called')
        print('args: ', args)
        result = cache.get(args, miss)
        if result is miss:
            print('miss')
            result = fn(*args)
            cache[args] = result
        return result

    print('memo finished')
    return wrapper


@memo
def fib(n):
    print('fib called')
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)


class MyDecorator(object):

    def __init__(self, fn):
        print("inside MyDecorator.__init__()")
        self.fn = fn

    def __call__(self):
        self.fn()
        print("inside MyDecorator.__call__()")


@MyDecorator
def a_function():
    print("inside a_function()")


print("Finished decorating a_function()")

if __name__ == '__main__':
    # print fib(5)
    a_function()
