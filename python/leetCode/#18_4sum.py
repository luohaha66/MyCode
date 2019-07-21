"""
Given an array nums of n integers and an integer target, are there elements a, b, c,
and d in nums such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
"""



class Solution:
    def fourSum(self, nums: list, target: int) -> list:
        nums.sort()
        res = []

        # The sum of four digits is transformed into the sum of two digits
        self.four_to_two(nums, target, [], res, 4)

        return res

    def four_to_two(self, nums, target, result, res, K):
        if K < 2:
            return
        if K == 2:
            start, end = 0, len(nums) - 1
            while start < end:
                val = nums[start] + nums[end]
                if val < target:
                    start += 1
                elif val > target:
                    end -= 1
                else:
                    res.append(result + [nums[start], nums[end]])
                    # remove repeated numbers
                    while start < end and nums[start] == nums[start + 1]:
                        start += 1
                    while start < end and nums[end] == nums[end - 1]:
                        end -= 1
                    start += 1
                    end -= 1
        else:
            for i in range(len(nums) - K + 1):
                if target < nums[i] * K or target > nums[-1] * K:
                    break
                # remove repeated numbers
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                self.four_to_two(nums[i + 1:], target - nums[i], result + [nums[i]], res, K - 1)


a = Solution()
print(a.fourSum([-3, -2, -1, 0, 0, 1, 2, 3], 0))
