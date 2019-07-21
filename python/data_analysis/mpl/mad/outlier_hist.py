import numpy as np
import matplotlib.pyplot as plt


def is_outlier(points, threshold=3.5):
    """
    :param points:
    :param threshold:
    :return: return true if points are outliers and false otherwise
    """
    # transform into vector
    if len(points.shape) == 1:
        points = points[:, None]
    # compute median value
    median = np.median(points, axis=0)
    # print(median)
    # compute diff sums along the axis
    diff = np.sum((points - median) ** 2, axis=-1)
    # print(diff)
    diff = np.sqrt(diff)
    # print(diff)
    # compute mad
    med_abs_deviation = np.median(diff)
    # print(med_abs_deviation)
    # compute modified Z-score
    modified_z_score = 0.6745 * diff / med_abs_deviation
    # return a mask for each outlier
    return modified_z_score > threshold


if __name__ == '__main__':
    # random data
    x = np.random.random(100)
    # print(x)
    # print(x.shape)
    # histograms buckets
    buckets = 50
    # add in a few outliers
    x = np.r_[x, -45, 95, 100, -100]
    # '~' is logical not on boolean numpy arrays
    filtered = x[~is_outlier(x)]
    # plot histograms
    plt.figure()
    plt.subplot(211)
    plt.hist(x, buckets)
    plt.xlabel('Raw')

    # plt.subplot(211)
    # plt.hist(filtered, buckets)
    # plt.xlabel('Cleaned')

    plt.show()
