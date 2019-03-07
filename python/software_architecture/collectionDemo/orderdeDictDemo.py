import collections
import pprint


class LRU(collections.OrderedDict):
    """
    least used recently cache dictionary
    """
    def __init__(self, size=10):
        super().__init__()
        self.size = size

    def set(self, key):
        # if key is there, delete and reinsert so it move to end
        if key in self:
            del self[key]

        # remove the oldest item
        self[key] = 1
        if len(self) > self.size:
            self.popitem(last=False)


if __name__ == '__main__':
    lru = LRU(4)
    lru.set('a')
    lru.set('b')
    lru.set('c')
    lru.set('d')
    pprint.pprint(lru)
    lru.set('e')
    pprint.pprint(lru)
    lru.set('f')
    pprint.pprint(lru)

    lru.set('d')
    pprint.pprint(lru)

    text = '123 123 456 456 5657'

    # freq = collections.Counter([])
    # pprint.pprint(freq)

    m = filter(None, map(lambda x: x.lower(), text.split(' ')))
    pprint.pprint(list(m))
