"""
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
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

