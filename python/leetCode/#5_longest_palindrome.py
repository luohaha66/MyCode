"""
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
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
