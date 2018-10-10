from concurrent.futures import ProcessPoolExecutor, as_completed, wait


def is_prime(n):
    if n % 2 == 0:
        return n, False
    sqrt_n = int(n ** 0.5)
    for i in range(3, sqrt_n + 1, 2):
        if n % i == 0:
            return n, False
    return n, True


if __name__ == '__main__':
    PRIMES = [
        112272535095293,
        112582705942171,
        112272535095293,
        115280095190773,
        115797848077099,
        1099726899285419]
    futures = []
    with ProcessPoolExecutor(max_workers=4) as pool:
        # Schedule the ProcessPoolExecutor to check if a number is prime
        # and add the returned Future to our list of futures
        for p in PRIMES:
            fut = pool.submit(is_prime, p)
            futures.append(fut)
    # As the jobs are completed, print out the results
    # The as_completed(futures) function returns an iterator over the list
    # of futures, yielding the futures as they complete
    # The wait(futures) function will simply block until all
    # futures in the list of futures provided have completed
    as_completed(futures)
    # or
    # wait(futures)
    for number, result in [x.result() for x in futures]:
        if result:
            print("{} is prime".format(number))
        else:
            print("{} is not prime".format(number))
