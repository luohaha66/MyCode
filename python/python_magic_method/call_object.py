"""
__call__(self, [args...]) Allows an instance of a class to be called as a function. Essentially, this means that x()
is the same as x.__call__(). Note that __call__ takes a
variable number of arguments; this means that you define __call__ as you would any
other function, taking however many arguments you’d like it to.
__call__ can be particularly useful in classes with instances that need to often change state.
\Calling" the instance can be an intuitive and elegant way to change the object’s state. An
example might be a class representing an entity’s position on a plane:
"""


class Entity:
    """Class to represent an entity . Callable to update
    the entity ’s position ."""

    def __init__(self, size, x, y):
        self.x, self.y = x, y
        self.size = size

    def __call__(self, x, y):
        # Change the position of the entity .
        self.x, self.y = x, y


if __name__ == '__main__':
    test = Entity(100, 100, 100)
    test(200, 200)
    print(test.x, test.y)