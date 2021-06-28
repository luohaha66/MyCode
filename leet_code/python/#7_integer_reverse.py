"""
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

注意:
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0
"""


class Solution:
    def reverse(self, x: int) -> int:

        if x >= 2147483647 or x <= -2147483648:
            return 0

        y = 0
        a = abs(x)
        while a != 0:
            a, reminder = divmod(a, 10)
            y = y * 10 + reminder

        if x > 0 and y < 2147483647:
            return y
        elif x < 0 and y <= 2147483647:
            return -y
        else:
            return 0


print(Solution().reverse(15342346))
print(2 ** 31, -2 ** 31 - 1)
