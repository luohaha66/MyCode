import random
import matplotlib
import matplotlib.pyplot as plt


if __name__ == '__main__':
    sample_size = 1000
    # histogram buckets
    buckets = 100
    plt.figure()
    # update font size
    matplotlib.rcParams.update({'font.size': 7})
    # create a grid 6*2
    plt.subplot(621)
    plt.xlabel('random.random')
    # return the next random floating number in the range [0.0, 1.0]
    res = [random.random() for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(622)
    plt.xlabel('random.uniform')
    # return a random floating point number N such that a <= N <= b for a <= b, and
    # b <= N <= a for b <= a
    a = 1
    b = sample_size
    res = [random.uniform(a, b) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(623)
    plt.xlabel('random.triangular')
    low = 1
    high = sample_size
    res = [random.triangular(low, high) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(624)
    plt.xlabel('random.betavariate')
    alpha = 1
    beta = 10
    res = [random.triangular(alpha, beta) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(625)
    plt.xlabel('random.expovariate')
    lambd = 1.0 / ((sample_size + 1) / 2.)
    res = [random.expovariate(lambd) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(626)
    plt.xlabel('random.gammavariate')
    alpha = 1
    beta = 10
    res = [random.gammavariate(alpha, beta) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(627)
    plt.xlabel('random.lognormvariate')
    mu = 1
    sigma = 0.5
    res = [random.lognormvariate(mu, sigma) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(628)
    plt.xlabel('random.normalvariate')
    mu = 1
    sigma = 10
    res = [random.normalvariate(mu, sigma) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.subplot(629)
    plt.xlabel('random.paretovariate')
    alpha = 1
    res = [random.paretovariate(alpha) for _ in range(1, sample_size)]
    plt.hist(res, buckets)

    plt.tight_layout()
    plt.show()
