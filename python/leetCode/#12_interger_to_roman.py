"""
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII.
Instead, the number four is written as IV. Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
"""


class Solution:
    def intToRoman(self, num: int) -> str:
        # version 1.0
        # from collections import deque
        #
        # roman = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL', 50: 'L', 90: 'XC',
        #          100: 'C', 400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'}
        # q = deque()
        #
        # i = 0
        # while num:
        #     num, digit = divmod(num, 10)
        #     times = pow(10, i)
        #     digit *= times
        #     i += 1
        #     if digit in roman:
        #         q.appendleft(roman[digit])
        #     elif digit >= 5 * times:
        #         q.appendleft(roman[times] * ((digit - 5 * times) // times))
        #         q.appendleft(roman[5 * times])
        #     else:
        #         q.appendleft(roman[times] * (digit // times))
        #
        # return ''.join(q)

        # version 2.0
        # roman = [
        #     ['', "M", "MM", "MMM"],
        #     ['', "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
        #     ['', "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
        #     ['', "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
        # ]
        # num_l = [1000, 100, 10, 1]
        # roman_num = ''
        #
        # for k, v in enumerate(num_l):
        #     roman_num += roman[k][num//v]
        #     num %= v
        # return roman_num

        # version 3.0 faster
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        reps = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        roman_num = ''

        for i in range(13):
            while num >= values[i]:
                num -= values[i]
                roman_num += reps[i]
        return roman_num


s = Solution()
print(s.intToRoman(3))
print(s.intToRoman(4))
print(s.intToRoman(5))
print(s.intToRoman(9))
print(s.intToRoman(58))
print(s.intToRoman(1994))
