# -*- coding: utf-8 -*-
"""
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是O(logn) 级别。
如果数组中不存在目标值，返回[-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
"""


class Solution:
    def searchRange(self, nums: list, target: int) -> list:
        return self.method_2(nums, target)

    def method_1(self, nums: list, target: int):
        # 二分法
        if not nums:
            return [-1, -1]
        l, r, e = 0, len(nums) - 1, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                start = mid
                end = mid
                while start >= 1 and nums[start - 1] == nums[mid]:
                    start -= 1
                while end <= e - 1 and nums[end + 1] == nums[mid]:
                    end += 1
                return [start, end]
            if target > nums[mid]:
                l = mid + 1
            else:
                r = mid - 1
        return [-1, -1]

    # returns leftmost (or rightmost) index at which `target` should be inserted in sorted
    # array `nums` via binary search.
    def extreme_insertion_index(self, nums, target, left):
        lo = 0
        hi = len(nums)

        while lo < hi:
            mid = (lo + hi) // 2
            if nums[mid] > target or (left and target == nums[mid]):
                hi = mid
            else:
                lo = mid + 1

        return lo

    def method_2(self, nums, target):
        left_idx = self.extreme_insertion_index(nums, target, True)

        # assert that `left_idx` is within the array bounds and that `target`
        # is actually in `nums`.
        if left_idx == len(nums) or nums[left_idx] != target:
            return [-1, -1]

        return [left_idx, self.extreme_insertion_index(nums, target, False) - 1]


s = Solution()
print(s.searchRange([5, 7, 7, 8, 8, 10], 6))

if __name__ == '__main__':
    ...
