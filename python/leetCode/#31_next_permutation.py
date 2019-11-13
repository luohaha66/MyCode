"""
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
"""


class Solution:
    def nextPermutation(self, nums: list) -> None:
        self.nextPermutation2(nums)

    def nextPermutation1(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        found = None
        for i in range(len(nums) - 1):
            if nums[i] < nums[i + 1]:
                found = i

        if found is None:
            nums.reverse()
        else:
            i, j = found + 1, len(nums) - 1
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
            for i in range(found + 1, len(nums)):
                if nums[i] > nums[found]:
                    nums[found], nums[i] = nums[i], nums[found]
                    break

    def binary_search(self, nums: list, target):
        start = 0
        end = len(nums) - 1

        if 0 == end:
            return 0

        while start + 1 != end:
            mid = (start + end) // 2
            if target >= nums[mid]:
                end = mid
            else:
                start = mid

        diff_end = nums[end] - target
        if diff_end <= 0:
            return start
        return end

    def swap(self, nums: list, i: int, j: int):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp

    def nextPermutation2(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len_nums = -len(nums)

        # 从数组末尾开始寻找，直到找到nums[i] < nums[i + 1], O(n)
        start_pos = -1
        while start_pos > len_nums:
            if nums[start_pos] > nums[start_pos - 1]:
                break
            start_pos -= 1

        if start_pos == len_nums:
            nums.sort()
            return

        # 找到nums[i + 1] ~ nums[len - 1]比nums[i]大的最小元素，与nums[i]进行交换,
        # 二分查找， O(log n)
        self.swap(nums, start_pos-1,
                  start_pos+self.binary_search(nums[start_pos:], nums[start_pos - 1]))
        print(nums)

        # 倒序nums[i + 1] ~ nums[len -1]， 因为[i + 1] ~ nums[len -1]已经是降序排列
        end = -1
        while start_pos < end:
            self.swap(nums, start_pos, end)
            start_pos += 1
            end -= 1
        print(nums)


Solution().nextPermutation([1, 1, 5])
