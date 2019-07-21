"""
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace
character is found. Then, starting from this character,
takes an optional initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace characters,
no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:
Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values,
INT_MAX (2*31 − 1) or INT_MIN (−2*31) is returned.

Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             INT_MIN (−231) is returned.
"""


class Solution:
    # version 1.0
    def myAtoi(self, strs: str) -> int:
        import re
        str_strip_blank = strs.lstrip(' ')
        if not str_strip_blank:
            return 0
        num_str = re.search(r'^[-+]?\d+', str_strip_blank)
        if num_str:
            num = int(num_str.group())
            if num < -2147483648:
                return -2147483648
            elif num > 2147483647:
                return 2147483647
            return int(num)
        return 0

    def version_one(self, strs: str) -> int:
        str_strip_blank = strs.lstrip(' ')
        if not str_strip_blank:
            return 0

        valid_start = {'+': 0, '-': 0}
        valid_num = {'0': 0, '1': 0, '2': 0, '3': 0,
                     '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0}
        if str_strip_blank[0] not in valid_start and str_strip_blank[0] not in valid_num:
            return 0
        start = 0
        if str_strip_blank[0] in valid_start:
            start = 1

        index = 0
        for each in str_strip_blank[start:]:
            if each in valid_num:
                index += 1
            else:
                break
        if index:
            num = int(str_strip_blank[0:index + start])
            if num < -2147483648:
                return -2147483648
            elif num > 2147483647:
                return 2147483647
            return int(num)
        return 0


a = Solution()
print(a.myAtoi('afads'))
print(a.myAtoi('-453543'))
print(a.myAtoi('-443543fafadfas'))
print(a.myAtoi('     4343dfasdf'))
print(a.myAtoi('   -334324dfasdf'))
print(a.myAtoi('3443432435435354352'))
print(a.myAtoi(''))
print(a.myAtoi('                 '))
print(a.myAtoi('                 asfafas'))
print(a.myAtoi('-'))
print(a.myAtoi('-afa'))
print(a.myAtoi('+'))
print(a.myAtoi('+afa'))
print(a.myAtoi('+13211    '))
print(a.myAtoi('  +13211adsfas'))
print(a.myAtoi('words and 898465'))
print(a.myAtoi('5'))
print(a.myAtoi('-5'))
print(a.myAtoi('   -5fasf'))
print(a.myAtoi('-5.131321'))
print(a.myAtoi(' +5.saasdfas'))
print(a.myAtoi('  +5.154654adfads'))
print(a.myAtoi('-0012a42'))
print(a.myAtoi('-5-'))
print(a.myAtoi('-5+5-6'))
