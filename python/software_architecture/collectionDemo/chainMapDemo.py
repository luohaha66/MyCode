import collections
import pprint


if __name__ == '__main__':
    d1 = {i: i for i in range(20)}
    d2 = {str(i): i * i for i in range(20)}
    c = collections.ChainMap(d1, d2)
    pprint.pprint(c)
    pprint.pprint(c[5])
    pprint.pprint(c['5'])
    pprint.pprint(c.maps[0][6])
    pprint.pprint(c.maps[1]['6 '])
