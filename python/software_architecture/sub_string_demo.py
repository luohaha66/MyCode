import memory_profiler
import random
import string


@memory_profiler.profile
def sub_string_brute(seq1, seq2):
    """
    brute force search
    """
    subs = []
    for item in seq2:
        for parent in seq1:
            if item in parent:
                subs.append(item)
    return subs


def test1():
    seq1 = ['capital', 'wisdom', 'material', 'category', 'wonder']
    seq2 = ['cap', 'mat', 'go', 'won', 'to', 'man']
    sub_string_brute(seq1, seq2)


def random_strings(n, m):
    """
    create m random strings in range of 4...n
    :param n:
    :param m:
    :return:
    """
    s1, s2 = [], []
    for i in range(m):
        s1.append(''.join(random.sample(string.ascii_lowercase, random.randrange(4, n))))

    for i in range(m):
        s2.append(''.join(random.sample(string.ascii_lowercase, random.randrange(4, n))))

    return s1, s2


def slices(s, n):
    return map(''.join, zip(*(s[i:] for i in range(n))))


@memory_profiler.profile
def sub_string(seq1, seq2):
    """
    :param seq1:
    :param seq2:
    :return: string from seq1 which are sub strings in seq2
    """
    # create all slices of length in a given range
    min_, max_ = min(map(len, seq1)), max(map(len, seq2))
    sequences = {}

    for i in range(min_, max_ + 1):
        for s in seq2:
            sequences.update({}.fromkeys(slices(s, i)))

    subs = []
    for item in seq1:
        if item in sequences:
            subs.append(item)
    return subs


def test2():
    s1, s2 = random_strings(10, 1000)
    # seq1 = ['cap', 'mat', 'go', 'won', 'to', 'man']
    # seq2 = ['capital', 'wisdom', 'material', 'category', 'wonder']
    print(sub_string(s1, s2))


if __name__ == '__main__':
    # s = 'abcdefg'
    # print(list(zip(*(s[i:] for i in range(5)))))
    # l = ['efg', 'abcdefg', 'bcdefg', 'cdefg', 'defg']
    # print(list(zip(*l)))
    test2()



