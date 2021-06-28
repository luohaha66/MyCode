"""
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
"""


class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Manacher's Algorithm
        if len(s) < 2 or s == s[::-1]:
            return s

        max_len = 1
        start = 0
        for i in range(1, len(s)):
            odd_start = i - max_len - 1
            even_start = i - max_len
            end = i + 1

            even = s[even_start: end]
            odd = s[odd_start: end]

            if odd_start >= 0 and odd == odd[::-1]:
                start = odd_start
                max_len += 2
                continue

            if even_start >= 0 and even == even[::-1]:
                print(even)
                start = even_start
                max_len += 1

        return s[start: start + max_len]
