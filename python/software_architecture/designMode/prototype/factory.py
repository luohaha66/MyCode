import copy


class Borg(object):
    """ I ain't a Singleton """
    __shared_state = {}

    def __init__(self):
        self.__dict__ = self.__shared_state


class SPrototype(object):
    """ A prototype base class using shallow copy """

    def clone(self):
        """ Return a clone of self """
        return copy.copy(self)


class Name(SPrototype):
    """ A class representing a person's name """

    def __init__(self, first, second):
        self.first = first
        self.second = second

    def __str__(self):
        return ' '.join((self.first, self.second))


class Animal(SPrototype):
    """ A class representing an animal """

    def __init__(self, name, type='Wild'):
        self.name = name
        self.type = type

    def __str__(self):
        return ' '.join((str(self.type), self.name))


class Address(SPrototype):
    """ An address class """

    def __init__(self, building, street, city, country):
        self.building = building
        self.street = street
        self.city = city
        self.country = country

    def __str__(self):
        return ', '.join((map(str, (self.building, self.street, self.city, self.country))))


class PrototypeFactory(Borg):
    """ A Prototype factory/registry class """

    def __init__(self):
        """ Initializer """

        super().__init__()
        self._registry = {}

    def register(self, instance):
        """ Register a given instance """

        self._registry[instance.__class__] = instance

    def clone(self, klass):
        """ Return cloned instance of given class """

        instance = self._registry.get(klass)
        if instance is None:
            print('Error:', klass, 'not registered')
        else:
            return instance.clone()


def proto_factory():
    # Illustrating factory
    name = Name('Bill', 'Bryson')
    animal = Animal('Elephant')
    factory = PrototypeFactory()

    factory.register(animal)
    factory.register(name)

    # Clone them
    name2 = factory.clone(Name)
    animal2 = factory.clone(Animal)

    print(name, name2)
    print(animal, animal2)
    print('name is not name2', name is not name2)
    print('animal is not animal2', animal is not animal2)

    class C:
        pass

    factory.clone(C)


proto_factory()
