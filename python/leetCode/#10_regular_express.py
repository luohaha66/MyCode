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


class Solution:
    cache = None

    def isMatch(self, s: str, p: str) -> bool:
        self.cache = [[None for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]
        return self.match(0, 0, s, p)

    def match(self, i: int, j: int, s: str, p: str) -> bool:
        print(i, j)
        if self.cache[i][j] is not None:
            return self.cache[i][j] is True
        if j == len(p):
            ans = i == len(s)
        else:
            cur_match = (i < len(s)) and (s[i] == p[j] or p[j] == '.')
            if j + 1 < len(p) and p[j + 1] == '*':
                ans = (self.match(i, j + 2, s, p)) or (cur_match and self.match(i + 1, j, s, p))
            else:
                ans = cur_match and self.match(i+1, j+1, s, p)
        self.cache[i][j] = True if ans else False
        return ans


s = Solution()
print(s.isMatch('aa', 'a*'))
