class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        if x >= 2 ** 31 or x <= -2 ** 31 - 1:
            return 0
        y = 0
        if x > 0:
            flag = 1
        else:
            flag = -1
        x = abs(x)
        while x != 0:
            a = x % 10
            x = int(x / 10)
            y = y * 10 + a
        return y * flag


print(Solution().reverse(153423469))
