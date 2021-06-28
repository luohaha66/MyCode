"""
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
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
