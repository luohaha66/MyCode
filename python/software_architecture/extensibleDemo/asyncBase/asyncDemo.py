import collections
import datetime
import asyncio


def number_generator(m, n):
    """
    a number generator co-routine in range (m, n+1)
    """
    yield from range(m, n+1)


async def square_generator(m, n):
    squares = []
    for i in number_generator(m, n):
        print('square=>', i * i)
        squares.append(i * i)
        # at this point co-routine suspend execution,
        # so that other co-routine can be scheduled
        await asyncio.sleep(0.3)
    return squares


async def is_prime(m, n):
    primes = []
    for i in number_generator(m, n):
        if i % 2 == 0:
            continue
        flag = True
        for j in range(3, int(i ** 0.5) + 1, 2):
            if i % j == 0:
                flag = False
        if flag:
            print('prime=>', i)
            primes.append(i)
            await asyncio.sleep(0.3)
    return primes


def print_result(future):
    print('result=>', future.result())


def scheduler():
    loop = asyncio.get_event_loop()
    future = asyncio.gather(is_prime(10, 20), square_generator(10, 20))
    future.add_done_callback(print_result)
    loop.run_until_complete(future)
    loop.close()


async def get_time():
    await asyncio.sleep(0.5)
    print(datetime.datetime.now())


def async_test():
    loop = asyncio.get_event_loop()
    future = asyncio.gather(get_time(), get_time(), get_time())
    loop.run_until_complete(future)
    loop.close()


async def main():
    print('Hello ...')
    await asyncio.sleep(1)
    print('... World!')

if __name__ == '__main__':
    # scheduler()
    # async_test()
    # new in 3.7+
    # Note that simply calling a coroutine will not schedule it to be executed
    asyncio.run(main())
