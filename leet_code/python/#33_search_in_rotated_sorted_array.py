# -*- coding: utf-8 -*-
"""
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组[0,1,2,4,5,6,7]可能变为[4,5,6,7,0,1,2])。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回-1。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是O(logn) 级别。

示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4

示例2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
"""


class Solution:
    def search(self, nums: list, target: int) -> int:
        return self.method_4(nums, target)

    def method_1(self, nums: list, target: int):
        try:
            return nums.index(target)
        except ValueError:
            return -1

    def method_2(self, nums: list, target: int):
        if not nums:
            return -1

        num_0 = nums[0]
        num_len = len(nums)
        if target >= num_0:
            i = 0
            while i < num_len:
                if target == nums[i]:
                    return i
                if i + 1 < num_len and nums[i] > nums[i+1]:
                    return -1
                i += 1
            return -1
        else:
            if target > nums[-1]:
                return -1
            i = -1
            num_len = -num_len
            while i > num_len:
                if target == nums[i]:
                    return i + len(nums)
                if i - 1 < num_len and nums[i] < nums[i - 1]:
                    return -1
                i -= 1
            return -1

    def method_3(self, nums: list, target: int):
        # 二分法
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            if nums[0] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[len(nums) - 1]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1

    def method_4(self, nums: list, target: int):
        # 二分法
        if not nums:
            return -1
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if (nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]):
                l = mid + 1
            else:
                r = mid
        return l if l == r and nums[l] == target else -1


s = Solution()
print(s.search([4, 5, 6, 7, 0, 1, 2], 7))
