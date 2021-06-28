"""
给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 
示例 1：
输入：
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。

示例 2：
输入：
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
输出：[]
"""


class Solution:
    def findSubstring(self, s: str, words: list) -> list:
        from collections import Counter
        if not s or not words:
            return []
        one_word = len(words[0])
        all_len = len(words) * one_word
        n = len(s)
        words = Counter(words)
        res = []
        for i in range(0, n - all_len + 1):
            tmp = s[i:i+all_len]
            c_tmp = [tmp[j:j+one_word] for j in range(0, all_len, one_word)]
            if Counter(c_tmp) == words:
                res.append(i)
        return res

    def findSubstring1(self, s: str, words: list) -> list:
        from collections import Counter
        if not s or not words: return []
        one_word = len(words[0])
        word_num = len(words)
        n = len(s)
        words = Counter(words)
        res = []
        for i in range(0, one_word):
            cur_cnt = 0
            left = i
            right = i
            cur_Counter = Counter()
            while right + one_word <= n:
                w = s[right:right + one_word]
                right += one_word
                cur_Counter[w] += 1
                cur_cnt += 1
                print('1', cur_Counter)
                while cur_Counter[w] > words[w]:
                    left_w = s[left:left + one_word]
                    left += one_word
                    cur_Counter[left_w] -= 1
                    cur_cnt -= 1
                    print('2', cur_Counter)
                if cur_cnt == word_num:
                    res.append(left)
                    print(res)
                print('3', cur_Counter)
            print('4', cur_Counter)
        return res

    def findSubstring2(self, s: str, words: list) -> list:
        """
        one_word为2，中间一个字符组成两个字符的字符串只有两种组合，（前1），（后1）
        one_word为3，中间一个字符组成两个字符的字符串有三种组合，（前1，后1），（前2），（后2）
        处理当前新截断的字符串w不满足words的要求，通过移动left，使（right-left）字符串满足要求。
        """
        from collections import Counter
        if not s or not words:
            return []
        one_word = len(words[0])
        word_num = len(words)
        n = len(s)
        if n < one_word*word_num:
            return []
        words = Counter(words)
        res = []
        for i in range(0, one_word):
            cur_cnt = 0
            left = i
            right = i
            cur_Counter = Counter()
            while right + one_word <= n:
                w = s[right:right + one_word]
                right += one_word
                if w not in words:
                    left = right
                    cur_Counter.clear()
                    cur_cnt = 0
                else:
                    cur_Counter[w] += 1
                    cur_cnt += 1
                    while cur_Counter[w] > words[w]:
                        left_w = s[left:left + one_word]
                        left += one_word
                        cur_Counter[left_w] -= 1
                        cur_cnt -= 1
                    if cur_cnt == word_num:
                        res.append(left)
        return res


if __name__ == '__main__':
    print(Solution().findSubstring2('barfoothefoobarman', ['foo', 'bar']))
