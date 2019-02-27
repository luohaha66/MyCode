"""
__cmp__(self, other) : __cmp__ is the most basic of the comparison magic methods. It
actually implements behavior for all of the comparison operators (<, ==, !=, etc.)
__cmp__ should return a negative integer if
self < other, zero if self == other, and positive if self > other. It’s usually best
to define each comparison you need rather than define them all at once, but __cmp__-
can be a good way to save repetition and improve clarity when you need all comparisons
implemented with similar criteria.
__eq__(self, other) Defines behavior for the equality operator, ==.
__ne__(self, other) Defines behavior for the inequality operator, !=.
__lt__(self, other) Defines behavior for the less-than operator, <.
__gt__(self, other) Defines behavior for the greater-than operator, >.
__le__(self, other) Defines behavior for the less-than-or-equal-to operator, <=.
__ge__(self, other) Defines behavior for the greater-than-or-equal-to operator, >=.
"""


class Word(str):
    """Class for words, defining comparison based on word length."""
    def __new__(cls, word):
        if word.startswith(' '):
            word = word.lstrip(' ')
        return str.__new__(cls, word)

    def __gt__(self, other):
        return len(self) > len(other)

    def __lt__(self, other):
        return len(self) < len(other)

    def __ge__(self, other):
        return len(self) >= len(other)

    def __le__(self, other):
        return len(self) <= len(other)


if __name__ == '__main__':
    print(Word('bar') > Word('foo'))
