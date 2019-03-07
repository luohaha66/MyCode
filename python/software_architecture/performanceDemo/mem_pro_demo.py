import memory_profiler


@memory_profiler.profile
def squares(n):
    return [x*x for x in range(1, n+1)]


if __name__ == '__main__':
    squares(10000)
