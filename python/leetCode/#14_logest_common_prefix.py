"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note:
All given inputs are in lowercase letters a-z.
"""


class Solution:
    def longestCommonPrefix(self, strs: list) -> str:
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

        if not all(strs) or not strs:
            return ''

        s1 = max(strs)
        s2 = min(strs)
        for i, c in enumerate(s1):
            if c != s2[i]:
                return s2[:i]
        return s1


s = Solution()
print(s.longestCommonPrefix(["flower", "flow", "flight"]))
print(s.longestCommonPrefix(["dog", "racecar", "car"]))
print(s.longestCommonPrefix(['ad', "cba"]))
