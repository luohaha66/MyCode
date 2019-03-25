import copy


class Prototype(object):
    """ A prototype base class """

    def clone(self):
        """ Return a clone of self """
        return copy.deepcopy(self)


class Register(Prototype):
    """ A student Register class  """

    def __init__(self, names):
        self.names = names


def deep_copy():
    r1 = Register(names=['amy', 'stu', 'jack'])
    r2 = r1.clone()
    print(r1)
    print(r2)
    print(r1 == r2)


deep_copy()
