import copy


class SPrototype(object):
    """ A prototype base class using shallow copy """

    def clone(self):
        """ Return a clone of self """
        return copy.copy(self)


class SRegister(SPrototype):
    """ Sub-class of SPrototype """

    def __init__(self, names):
        self.names = names


def shadow_copy():
    r1 = SRegister(names=['amy', 'stu', 'jack'])
    r2 = r1.clone()

    r1.names.append('bob')
    print('r1.names==r2.names', r1.names == r2.names)
    print('r1.names is r2.names', r1.names is r2.names)


shadow_copy()
