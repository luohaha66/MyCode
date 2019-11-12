"""
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。

示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
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
