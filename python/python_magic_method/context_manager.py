"""
Context managers allow setup and cleanup actions to be taken for objects when their creation
is wrapped with a with statement. The behavior of the context manager is determined by two
magic methods:
__enter__(self) Defines what the context manager should do at the beginning of the block
created by the with statement. Note that the return value of __enter__ is bound to the
target of the with statement, or the name after the as.
__exit__(self, exception_type, exception_value, traceback) Defines what the context
manager should do after its block has been executed (or terminates). It can be used to
handle exceptions, perform cleanup, or do something always done immediately after the
action in the block. If the block executes successfully, exception_type, exception_-
value, and traceback will be None. Otherwise, you can choose to handle the exception
or let the user handle it; if you want to handle it, make sure __exit__ returns True
after all is said and done. If you don’t want the exception to be handled by the context
manager, just let it happen.
__enter__ and __exit__ can be useful for specific classes that have well-defined and common behavior
for setup and cleanup. You can also use these methods to create generic context
managers that wrap other objects. Here’s an example:
"""


class Closer:
    """A context manager to automatically close an object with a
    close () method in a with statement ."""

    def __init__(self, obj):
        self.obj = obj

    def __enter__(self):
        return self.obj  # bound to target

    def __exit__(self, exception_type, exception_val, traceback):
        try:
            self.obj.close()
        except AttributeError:  # obj isn ’t closable
            print('Not closable.')
            return True  # exception handled successfully


if __name__ == '__main__':
    with Closer('i love you') as conn:
        conn = '{} i hate you'.format(conn)
        print(conn)
