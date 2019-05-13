"""
Given an array nums of n integers and an integer target, find three integers in nums such
that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""


class Solution:
    def threeSumClosest(self, nums: list, target: int) -> int:
        res = []
        nums.sort()

        print(nums)
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                # jumped repeated numbers
                continue

            j = i + 1
            k = len(nums) - 1

            # nums[i] + nums[k] + nums[k - 1] is max for current iteration
            # if nums[i] + nums[k] + nums[k - 1] < target:
            # nums[i] + nums[k] + nums[k - 1] is closest to target
            # nums[i] + nums[j] + nums[j + 1] are the same
            if nums[i] + nums[k] + nums[k - 1] < target:
                res.append(nums[i] + nums[k] + nums[k - 1])
            elif nums[i] + nums[j] + nums[j + 1] > target:
                res.append(nums[i] + nums[j] + nums[j + 1])
            else:
                while j < k:
                    s = nums[i] + nums[j] + nums[k]
                    res.append(s)
                    if s == target:
                        return target
                    elif s < target:
                        j += 1
                    else:
                        k -= 1
        res.sort(key=lambda x: abs(x - target))
        return res[0]


s = Solution()
print(s.threeSumClosest([-1, 2, 1, -4], 1))

