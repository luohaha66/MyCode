"""
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，
而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:
输入: 3
输出: "III"

示例 2:
输入: 4
输出: "IV"

示例 3:
输入: 9
输出: "IX"

示例 4:
输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.

示例 5:
输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
"""


class Solution:
    def intToRoman(self, num: int) -> str:
        # version 3.0 faster
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        reps = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        roman_num = ''

        for i in range(13):
            while num >= values[i]:
                num -= values[i]
                roman_num += reps[i]
        return roman_num

    def version_one(self, num: int) -> str:
        # version 1.0
        from collections import deque

        roman = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC',
                 100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
        q = deque()

        i = 0
        while num:
            num, digit = divmod(num, 10)
            times = pow(10, i)
            digit *= times
            i += 1
            if digit in roman:
                q.appendleft(roman[digit])
            elif digit >= 5 * times:
                q.appendleft(roman[times] * ((digit - 5 * times) // times))
                q.appendleft(roman[5 * times])
            else:
                q.appendleft(roman[times] * (digit // times))

        return ''.join(q)

    def version_two(self, num: int) -> str:
        # version 2.0
        roman = [
            ['', "M", "MM", "MMM"],
            ['', "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            ['', "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            ['', "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
        ]
        num_l = [1000, 100, 10, 1]
        roman_num = ''

        for k, v in enumerate(num_l):
            roman_num += roman[k][num//v]
            num %= v
        return roman_num

s = Solution()
print(s.intToRoman(3))
print(s.intToRoman(4))
print(s.intToRoman(5))
print(s.intToRoman(9))
print(s.intToRoman(58))
print(s.intToRoman(1994))
