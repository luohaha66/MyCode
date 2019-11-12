"""
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:
输入: dividend = 10, divisor = 3
输出: 3

示例 2:
输入: dividend = 7, divisor = -3
输出: -2

说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
"""


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        # if abs(divisor) > abs(dividend):
        #     return 0
        # if dividend > 2147483647 or dividend < -2147483648:
        #     return 2147483647
        return self.version2(dividend, divisor)

    def same_symbol(self, dividend: int, divisor: int) -> int:
        # judge whether dividend and divisor have the same symbol
        if dividend >> 31 == divisor >> 31:
            symbol = 1
        else:
            symbol = -1
        # if dividend ^ divisor > 0:
        #     symbol = 1
        # else:
        #     symbol = -1
        return symbol

    def version1(self, dividend: int, divisor: int) -> int:
        symbol = self.same_symbol(dividend, divisor)
        dividend, divisor = abs(dividend), abs(divisor)
        result = 0
        while dividend >= divisor:
            dividend -= divisor
            result += 1
        result *= symbol
        if result >= 2147483647 or result <= -2147483648:
            return 2147483647
        return result

    def version2(self, dividend: int, divisor: int) -> int:
        def recursion_left_shift(div: int, div_c: int, count: int):
            print(div, div_c, count)
            shift = 0
            temp = div_c
            while (temp << 1) <= div:
                temp <<= 1
                shift += 1
            div -= temp
            if 0 == shift and div < div_c:
                if div >= 0:
                    count += 1
                print(count)
                return count
            elif shift:
                count += (1 << shift)
            return recursion_left_shift(div, div_c, count)

        symbol = -1 if (dividend > 0) ^ (divisor > 0) else 1
        dividend, divisor = abs(dividend), abs(divisor)
        result = 0
        result = recursion_left_shift(dividend, divisor, result)
        result *= symbol
        return result if -2147483648 <= result <= 2147383647 else 2147483647

    def version3(self, dividend: int, divisor: int) -> int:
        sign = (dividend > 0) ^ (divisor > 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        count = 0
        # 把除数不断左移，直到它大于被除数
        while dividend >= divisor:
            count += 1
            divisor <<= 1
        result = 0
        while count > 0:
            count -= 1
            divisor >>= 1
            if divisor <= dividend:
                result += 1 << count  # 这里的移位运算是把二进制（第count+1位上的1）转换为十进制
                dividend -= divisor
        if sign:
            result = -result
        return result if -(1<<31) <= result <= (1<<31)-1 else (1<<31)-1


if __name__ == '__main__':
    print(Solution().divide(10, 3))
