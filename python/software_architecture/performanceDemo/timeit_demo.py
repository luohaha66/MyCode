import timeit


def test(n):
    return [x for x in range(n)]


if __name__ == '__main__':
    print(timeit.timeit(stmt='test(10000)', setup='from __main__ import test',
                        timer=timeit.default_timer, number=10000))
    print(timeit.repeat(stmt='test(10000)', setup='from __main__ import test',
                        timer=timeit.default_timer, repeat=10, number=1000))
