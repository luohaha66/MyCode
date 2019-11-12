"""
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。
"""


class Solution:
    def longestCommonPrefix(self, strs: list) -> str:
        if not all(strs) or not strs:
            return ''

        s_min = min(strs)
        s_max = max(strs)

        if len(s_max) < len(s_min):
            s_min, s_max = s_max, s_min

        for i, c in enumerate(s_min):
            if c != s_max[i]:
                return s_max[:i]
        return s_min

    def version_one(self, strs: list) -> str:
        if not all(strs) or not strs:
            return ''

        ss = list(map(set, zip(*strs)))
        res = ''
        for i, x in enumerate(ss):
            x = list(x)
            if len(x) > 1:
                break
            res += x[0]
        return res

    def version_two(self, strs: list) -> str:
        if not all(strs) or not strs:
            return ''
        if len(strs) == 1:
            return strs[0]

        first_str = strs[0]
        index = 0

        for each in range(0, len(first_str)):
            flag = True
            for string in strs[1:]:
                if not string.startswith(first_str[0: each + 1]):
                    flag = False
                    break
            if not flag:
                break
            index += 1

        if not index:
            return ''
        return first_str[0: index]

s = Solution()
print(s.longestCommonPrefix(["flower", "flow", "flight"]))
print(s.longestCommonPrefix(["dog", "racecar", "car"]))
print(s.longestCommonPrefix(['ad', "cba"]))
