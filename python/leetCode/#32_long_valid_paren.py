"""
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"

示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
"""


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        return self.method1(s)

    def iter_str(self, s: str, char: str, start: int, end: int, step: int) -> int:
        sums = cur_s_len = max_sub_len = 0
        for i in range(start, end, step):
            sums += (1 if s[i] == char else -1)
            cur_s_len += 1
            if sums == 0:
                max_sub_len = cur_s_len if cur_s_len > max_sub_len else max_sub_len
            elif sums < 0:
                sums = cur_s_len = 0
        return max_sub_len

    def method1(self, s: str) -> int:
        """
        利用两个计数器 left 和 right.
        首先，我们从左到右遍历字符串，对于遇到的每个‘(’，我们增加 left 计算器，
        对于遇到的每个‘)’ ，我们增加 right 计数器。
        每当 left 计数器与 right 计数器相等时，
        我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。
        如果 right 计数器比 left 计数器大时，我们将 left 和 right 计数器同时变回0。
        接下来，我们从右到左做一遍类似的工作
        :param s:
        :return:
        """
        return max(self.iter_str(s, '(', 0, len(s), 1), self.iter_str(s, ')', -1, -len(s), -1))


print(Solution().longestValidParentheses('(()()())())))((((((((((((((()))))(())))))))))))))((()'))
