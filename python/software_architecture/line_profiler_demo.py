from line_profiler import LineProfiler
import cProfile
import pstats


def is_prime(n):
    vroot = int(n ** 0.5) + 1
    for i in range(3, vroot, 2):
        if n % i == 0:
            return False
    return True


def test1():
    cProfile.run('is_prime(77335533)')


def test2():
    prof = cProfile.Profile()
    prof.enable()
    is_prime(77335533)
    prof.create_stats()

    p = pstats.Stats(prof)
    p.print_callees()


def test3():
    p = LineProfiler()
    p.add_function(is_prime)
    l = p(is_prime)
    l(775533)
    p.print_stats()


if __name__ == '__main__':
    test3()
