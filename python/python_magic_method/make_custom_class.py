"""
__len__(self) Returns the length of the container. Part of the protocol for both immutable
and mutable containers.
__getitem__(self, key) Defines behavior for when an item is accessed, using the notation
self[key]. This is also part of both the mutable and immutable container protocols. It
should also raise appropriate exceptions: TypeError if the type of the key is wrong and
KeyError if there is no corresponding value for the key.
__setitem__(self, key, value) Defines behavior for when an item is assigned to, using the
notation self[key] = value. This is part of the mutable container protocol. Again, you
should raise KeyError and TypeError where appropriate.
__delitem__(self, key) Defines behavior for when an item is deleted (e.g. del self[key]).
This is only part of the mutable container protocol. You must raise the appropriate
exceptions when an invalid key is used.
__iter__(self) Should return an iterator for the container. Iterators are returned in a number
of contexts, most notably by the iter() built in function and when a container is looped
over using the form for x in container:. Iterators are their own objects, and they also
must define an __iter__ method that returns self.
__reversed__(self) Called to implement behavior for the reversed() built in function.
Should return a reversed version of the sequence. Implement this only if the sequence
class is ordered, like list or tuple.
__contains__(self, item) __contains__ defines behavior for membership tests using in
and not in. Why isn’t this part of a sequence protocol, you ask? Because when __-
contains__ isn’t defined, Python just iterates over the sequence and returns True if it
comes across the item it’s looking for.
__missing__(self, key) __missing__ is used in subclasses of dict. It defines behavior for
whenever a key is accessed that does not exist in a dictionary (so, for instance, if I had
a dictionary d and said d["george"] when "george" is not a key in the dict, d.__-
missing__("george") would be called)

__instancecheck__(self, instance) Checks if an instance is an instance of the class you
defined (e.g. isinstance(instance, class).
__subclasscheck__(self, subclass) Checks if a class subclasses the class you defined (e.g.
issubclass(subclass, class)).
"""


class FunctionalList:
    """A class wrapping a list with some extra functional
    magic , like head , tail , init , last , drop , and take ."""

    def __init__(self, values=None):
        if values is None:
            self.values = []
        else:
            self.values = values

    def __len__(self):
        return len(self.values)

    def __getitem__(self, key):
        # if key is of invalid type or value , the list values
        # will raise the error
        return self.values[key]

    def __setitem__(self, key, value):
        if key >= (len(self.values) - 1):
            self.values.append(value)
        else:
            self.values[key] = value

    def __delitem__(self, key):
        del self.values[key]

    def __iter__(self):
        return iter(self.values)

    def __reversed__(self):
        return reversed(self.values)

    def append(self, value):
        self.values.append(value)

    def head(self):
        # get the first element
        return self.values[0]

    def tail(self):
        # get all elements after the first
        return self.values[1:]

    def init(self):
        # get elements up to the last
        return self.values[: -1]

    def last(self):
        # get last element
        return self.values[-1]

    def drop(self, n):
        # get all elements except first n
        return self.values[n:]

    def take(self, n):
        # get first n elements
        return self.values[:n]


if __name__ == '__main__':
    test = FunctionalList()
    test[0] = 1
    test[1] = 2
    test[2] = 3
    for each in test:
        print(each)
    print(test[0])
    print(len(test))
