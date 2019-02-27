import collections as cl


def rotate_seq1(seq1, n):
    """
    :return: a rotated list
    """
    k = len(seq1) - n
    return seq1[k:] + seq1[:k]


def rotate_seq2(seq2, n):
    """
    deque, pop or append form head or tail, O(1)
    :return:
    """
    d = cl.deque(seq2)
    d.rotate(n)
    return list(d)


if __name__ == '__main__':
    print(rotate_seq1([1, 2, 3, 4, 5], 3))
    print(rotate_seq2([1, 2, 3, 4, 5], 3))
