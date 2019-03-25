"""
The function of yield is to turn a function into a generator.
A function with yield is no longer a normal function.
The Python interpreter treats it as a generator. Calling function (arg) does not execute a function,
but returns an Iterable object! When the for loop executes,
each loop executes the code inside the function.
When the function is executed to yield, the function returns an iteration value.
The next iteration, the code continues to execute from the next statement of yield,
and the local variable of the function looks exactly the same as before the last interruption,
so the function continues to execute until it encounters yield again.

A function with yield is a generator, which, unlike a normal function,
generates a generator that looks like a function call,
but does not execute any function code until it calls next () (which is automatically called next () in the for loop).
Although the execution process is still executed according to the process of the function,
every time a yield statement is executed, it interrupts and returns an iteration value.
The next execution continues from the next statement of yield.
It looks like a function is interrupted several times by yield during normal execution,
and each interrupt returns the current iteration value through yield

the function of return:
In a generator function, if not return, it defaults to the function is completed,
if the return in the implementation process, directly thrown StopIteration iteration is terminated
"""
import collections
import datetime


def number_generator(n):
    for i in range(1, n + 1):
        yield i


def square_generator(n):
    for i in n:
        yield i * i


def is_prime(n):
    for i in n:
        if i % 2 == 0:
            continue
        flag = True
        for j in range(3, int(i ** 0.5) + 1, 2):
            if i % j == 0:
                flag = False
        if flag:
            yield i


def scheduler(tasks, runs=100):
    results = collections.defaultdict(list)

    for i in range(runs):
        for t in tasks:
            print('switch to task: ', t.__name__)
            try:
                result = t.__next__()
            except StopIteration:
                break
            print('result=> ', result)
            results[t.__name__].append(result)
    return results


if __name__ == '__main__':
    a = datetime.datetime.now()
    tasks = [
        square_generator(number_generator(10)),
        is_prime(number_generator(10))
    ]

    results = scheduler(tasks, 10)
    print('last prime=>', results['is_prime'][-1])
    print('cost time', datetime.datetime.now() - a)
