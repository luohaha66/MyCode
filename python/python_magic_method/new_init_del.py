"""
__new__(cls, [...) __new__ is the first method to get called in an object’s instantiation, It takes
the class, then any other arguments that it will pass along to __init__.
__init__(self, [...) The initializer for the class.
__del__(self) If __new__ and __init__ formed the constructor of the object, __del__ is the
destructor
"""

import os


class FileObject:
    def __init__(self, filepath='.', filename='test.txt'):
        print('init method called')
        # open a file filename in filepath in read and write mode
        self.file = open(os.path.join(filepath, filename), 'w+')

    def __del__(self):
        print('del method called')
        self.file.close()
        del self.file


if __name__ == '__main__':
    f = FileObject()
