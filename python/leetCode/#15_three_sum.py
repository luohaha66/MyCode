"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""


class Solution:
    def threeSum(self, nums: list) -> list:
        from bisect import bisect_left, bisect_right

        target = 0

        result = []

        length = len(nums)

        if length < 3:
            return result

        count = {}
        # map the counts
        for n in nums:
            if n in count:
                count[n] += 1
            else:
                count[n] = 1
        keys = list(count.keys())
        keys.sort()
        print(count)
        print(keys)

        t3 = 0
        if t3 in keys and count[t3] >= 3:
            result.append([t3, t3, t3])

        print(result)

        begin = 0
        end = bisect_left(keys, 0)
        print(begin, end)

        for i in range(begin, end):
            a = keys[i]
            if count[a] >= 2 and target - 2 * a in count:
                result.append([a, a, target - 2 * a])
                break

            max_b = (target - a) // 2  # target-a is remaining
            min_b = target - a - keys[-1]  # target-a is remaining and can max be keys[-1]
            b_begin = max(i + 1, bisect_left(keys, min_b))
            b_end = bisect_right(keys, max_b)

            for j in range(b_begin, b_end):
                b = keys[j]
                c = target - a - b
                if c in count and b <= c:
                    if b < c or count[b] >= 2:
                        result.append([a, b, c])
        return result


s = Solution()
print(s.threeSum([3,0,-2,-1,1,2]))

# [[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
