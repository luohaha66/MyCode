"""
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
"""


class Solution:
    cache = {1: ['()'], 0: ['']}

    def generateParenthesis(self, n):
        ret = []
        if n in self.cache:
            return self.cache[n]
        for i in range(n):
            inners = self.generateParenthesis(i)
            outers = self.generateParenthesis(n-i-1)
            for inner in inners:
                for outer in outers:
                    ret.append('(' + inner + ')' + outer)
        return ret

    # O(pow(2, 2n) * n)
    def version_one(self, n: int) -> list:
        res = []

        def valid(s: str) -> bool:
            bal = 0
            for c in s:
                if c is '(':
                    bal += 1
                else:
                    bal -= 1
                if bal < 0:
                    return False
            return bal == 0

        def generate_all(result: list, strs: str):
            if len(strs) == n * 2:
                if valid(strs):
                    result.append(strs)
            else:
                generate_all(result, strs + '(')
                generate_all(result, strs + ')')

        generate_all(res, '')

        return res

    def version_two(self, n: int) -> list:
        res = []

        def gererate(strs='', left=0, right=0):
            if len(strs) == n * 2:
                res.append(strs)
                return
            if left < n:
                gererate(strs + '(', left + 1, right)
            if right < left:
                gererate(strs + ')', left, right + 1)

        gererate()
        return res


s = Solution()
print(s.generateParenthesis(3))
