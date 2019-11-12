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
        self.nextPermutation1(nums)

    def nextPermutation1(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len_nums = -len(nums)

        # 从数组末尾开始寻找找，直到找到nums[i] < nums[i + 1], O(n)
        start_pos = -1
        while start_pos > len_nums:
            if nums[start_pos] > nums[start_pos - 1]:
                break
            start_pos -= 1

        if start_pos == len_nums:
            nums.sort()
            return

        # 找到nums[i + 1] ~ nums[len - 1]比nums[i]大的最小元素，与nums[i]进行交换, O(n)
        replace_num = nums[start_pos - 1]
        left_nums = nums[start_pos:]
        min_value = 30
        replace_index = 0
        for i in range(len(left_nums)):
            value = left_nums[i] - replace_num
            if 0 < value < min_value:
                replace_index = i
                min_value = value
        nums[start_pos - 1] = left_nums[replace_index]
        nums[start_pos + replace_index] = replace_num

        # 排序nums[i + 1] ~ nums[len -1]
        # 计数排序，O(n+k)
        print(start_pos)
        if start_pos < -1:
            count_list = [0 for _ in range(30)]
            for i in range(start_pos, 0, 1):
                count_list[nums[i]] += 1
            print(count_list)
            for i in range(30):
                while count_list[i] > 0:
                    nums[start_pos] = i
                    print(nums[start_pos])
                    count_list[i] -= 1
                    start_pos += 1

        print(nums)

    def nextPermutation2(self, nums: list) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        len_nums = -len(nums)

        # 从数组末尾开始寻找找，直到找到nums[i] < nums[i + 1], O(n)
        start_pos = -1
        while start_pos > len_nums:
            if nums[start_pos] > nums[start_pos - 1]:
                break
            start_pos -= 1

        if start_pos == len_nums:
            nums.sort()
            return

        # 找到nums[i + 1] ~ nums[len - 1]比nums[i]大的最小元素，与nums[i]进行交换, O(n)
        replace_num = nums[start_pos - 1]
        left_nums = nums[start_pos:]
        min_value = 30
        replace_index = 0
        for i in range(len(left_nums)):
            value = left_nums[i] - replace_num
            if 0 < value < min_value:
                replace_index = i
                min_value = value
        nums[start_pos - 1] = left_nums[replace_index]
        nums[start_pos + replace_index] = replace_num

        # 排序nums[i + 1] ~ nums[len -1]
        # 计数排序，O(n+k)
        print(start_pos)
        if start_pos < -1:
            count_list = [0 for _ in range(30)]
            for i in range(start_pos, 0, 1):
                count_list[nums[i]] += 1
            print(count_list)
            for i in range(30):
                while count_list[i] > 0:
                    nums[start_pos] = i
                    print(nums[start_pos])
                    count_list[i] -= 1
                    start_pos += 1

        print(nums)


Solution().nextPermutation([11,12,0,27,3,11,21,9,0,15,26,27,17,24,0,16,4,17,14,8,15,8,2,16,10,6,6,24,16,2,18,19,6,10,17,10,21,0,11,13,7,7,2,16,24,25,2,20,12,9,20,19])
