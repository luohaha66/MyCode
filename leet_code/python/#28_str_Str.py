"""
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
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
