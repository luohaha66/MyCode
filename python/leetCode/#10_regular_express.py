"""
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
"""


class BaseStr:
    def __init__(self, p: str):
        self.p = p
        self.index = 0
        self.len = len(p)

    def get(self):
        if self.index < self.len:
            return self.p[self.index]
        return None

    def get_last(self):
        if self.index:
            return self.p[self.index - 1]
        return None

    def get_next(self):
        if self.index + 1 < self.len:
            return self.p[self.index + 1]
        return None

    def next(self):
        self.index += 1


class Source(BaseStr):
    ...


class Pattern(BaseStr):
    ...


class Solution:
    def __init__(self):
        self.character = {each: 0 for each in 'abcdefghijklmnopqrstuvwxyz'}

    def is_character(self, char: str):
        return char in self.character

    def is_dot(self, char: str):
        return char == '.'

    def is_asterisk(self, char: str):
        return char == '*'

    def match_character(self, s: Source, p: Pattern):
        char = s.get()
        if char:
            if char == p.get():
                s.next()
                p.next()
                return True
            return False
        return False

    def match_dot(self, s: Source, p: Pattern):
        char = s.get()
        if char:
            s.next()
            p.next()
            return True
        # pattern '.*' and source str is reaching the end
        elif p.get_next() and p.get_next() == '*':
            p.next()
            return True
        else:
            return False

    def find_char(self, s: Source, p: str):
        while s.get() == p:
            s.next()

    def find_any(self, s: Source, p: str):
        if p:
            while s.get() != p:
                s.next()
        else:
            while s.get():
                s.next()

    def match_asterisk(self, s: Source, p: Pattern):
        # '*' can only use with the combination of the last char
        char = p.get_last()
        if char:
            if self.is_character(char):
                # find char in source str zero or more times
                self.find_char(s, char)
            elif self.is_dot(char):
                p.next()
                p_char = p.get()
                while p_char and not self.is_character(p_char):
                    p.next()
                    p_char = p.get()
                    if self.is_asterisk(p_char):
                        return False
                self.find_any(s, p_char)
            return True

    def isMatch(self, s: str, p: str) -> bool:

