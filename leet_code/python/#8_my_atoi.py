"""
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。
当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，
作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。
在任何情况下，若函数不能进行有效的转换时，请返回 0。
说明：
假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，
请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。

示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
     因此返回 INT_MIN (−231) 。
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
