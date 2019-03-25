import copy


class MetaPrototype(type):
    """ A metaclass for Prototypes """

    def __init__(cls, *args):
        type.__init__(cls, *args)
        cls.clone = lambda self: copy.deepcopy(self)


class MetaSingletonPrototype(type):
    """ A metaclass for Singleton & Prototype patterns """

    def __init__(cls, *args):
        print(cls, "__init__ method called with args", args)
        type.__init__(cls, *args)
        cls.instance = None
        cls.clone = lambda self: copy.deepcopy(cls.instance)

    def __call__(cls, *args, **kwargs):
        if not cls.instance:
            print(cls, "creating prototypical instance", args, kwargs)
            cls.instance = type.__call__(cls, *args, **kwargs)
        return cls.instance


class PrototypeM(metaclass=MetaSingletonPrototype):
    """ Top-level prototype class using MetaSingletonPrototype """
    pass


class ItemCollection(PrototypeM):
    """ An item collection class """

    def __init__(self, items):
        self.items = items


def single_proto():
    i1 = ItemCollection(items=['apples', 'grapes', 'oranges'])
    print(i1)
    # Invokes the Prototype API
    i2 = i1.clone()
    print('i1.items is i2.items', i1.items is i2.items)
    # Invokes the Singleton API
    i3 = ItemCollection(items=['apples', 'grapes', 'oranges'])
    print('i1 is i3', i1 is i3)


single_proto()
