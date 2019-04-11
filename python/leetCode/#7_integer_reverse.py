"""

"""


class Solution:
    def reverse(self, x: int) -> int:

        if x >= 2147483647 or x <= -2147483648:
            return 0

        y = 0
        a = abs(x)
        while a != 0:
            reminder = a % 10
            a = int(a / 10)
            y = y * 10 + reminder

        if x > 0 and y < 2147483647:
            return y
        elif x < 0 and y <= 2147483647:
            return -y
        else:
            return 0


print(Solution().reverse(15342346))
print(2 ** 31, -2 ** 31 - 1)
