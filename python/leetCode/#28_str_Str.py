"""
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
"""


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return self.sunday_search(haystack, needle)

    def sunday_search(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        offset = {}
        n_l = len(needle)

        for i in range(n_l):
            offset[needle[i]] = n_l - i

        i, j, h_l = 0, 0, len(haystack)

        while i <= h_l - n_l:
            j = 0

            while haystack[i + j] == needle[j]:
                j += 1
                if j == n_l:
                    return i

            if i + n_l == h_l:
                return -1

            if haystack[i + n_l] in offset:
                i += offset[haystack[i + n_l]]
            else:
                i += n_l + 1

        return -1

    def kmp_search(self, haystack: str, needle: str) -> int:

        def get_next(pattern: str):
            j, k, l = 0, -1, len(pattern)

            p_next = [-1 for _ in range(l)]

            while j < l - 1:
                if k == -1 or pattern[j] == pattern[k]:
                    k += 1
                    j += 1
                    if pattern[j] != pattern[k]:
                        p_next[j] = k
                    else:
                        p_next[j] = p_next[k]
                else:
                    k = p_next[k]

            return p_next

        i, j, h_l, n_l = 0, 0, len(haystack), len(needle)
        p_next = get_next(needle)

        while i < h_l and j < n_l:
            if j == -1 or haystack[i] == needle[j]:
                i += 1
                j += 1
            else:
                j = p_next[j]

        if j == n_l:
            return i - j
        return -1


s = Solution()
index = s.strStr('hello', 'll')
print(index)

from collections import defaultdict

a = defaultdict()
