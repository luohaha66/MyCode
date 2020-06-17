"""
coding: utf-8
"""

from matplotlib import pyplot as plt
import matplotlib
import random
import numpy as np


def my_range(i: float, j: float, k: float) -> list:
    decimals = str((len(str(k - int(k))) - 2) / 10) + "f"

    range_l = []
    while i < j:
        range_l.append(float(format(i, decimals)))
        i += k
    return range_l


def polygonal_chart():
    # set font
    font = {'family': 'Microsoft YaHei',
            'weight': 'bold'}
    matplotlib.rc('font', **font)

    x = range(0, 120, 1)
    y = [random.randint(20, 35) for _ in range(120)]

    # set image size and image dpi
    # plt.figure(figsize=(20, 8))

    # draw plot
    plt.plot(x, y, label='tmp', color='cyan')

    # set X-axis step
    marks = [f"第 {i}" for i in range(13)]
    plt.xticks(my_range(0, 130, 10), marks, rotation=45)
    plt.yticks(my_range(20, 36, 2))

    # add describe info
    plt.xlabel("Time")
    plt.ylabel("Tmp")
    plt.title("temperature info")
    plt.legend()

    # save image
    # plt.savefig("./temp.png")

    # show
    plt.show()


def scatter_plot():
    x = [random.randint(10, 30) for _ in range(30)]
    y = [i for i in range(30)]

    plt.scatter(x, y)
    plt.show()


def bar_graph_v():
    x = [i for i in range(6)]
    y = [random.randint(10, 30) for _ in range(6)]

    plt.bar(x, y)
    plt.xticks(x, ['a', 'b', 'c', 'd', 'e', 'f'])
    plt.show()


def bar_graph_h():
    x = [random.randint(10, 30) for _ in range(6)]
    y = [i for i in range(6)]

    plt.barh(y, x)
    plt.yticks(y, ['a', 'b', 'c', 'd', 'e', 'f'])
    plt.show()


def hist_plot():
    x = [random.randint(10, 50) for _ in range(50)]

    bin_width = 10
    num_bins = len(x) // bin_width
    plt.hist(x, num_bins)

    plt.xticks(range(10, 50+bin_width, bin_width))

    plt.show()


def hist_plot_1():
    interval = [0, 5, 10, 15, 60, 90, 150]
    width = [5, 5, 5, 5, 15, 30]
    quantiy = [836, 2737, 3723, 3926, 215, 47]

    plt.bar(range(len(quantiy)), quantiy, width=1)
    plt.xticks(my_range(-0.5, 6.5, 1), interval)

    plt.show()


if __name__ == '__main__':
    # bar_graph_h()
    x = np.random.normal(size=10)
