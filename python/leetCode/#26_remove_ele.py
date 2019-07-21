"""
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:
Given nums = [3,2,2,3], val = 3,
Your function should return length = 2, with the first two elements of nums being 2.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,1,2,2,3,0,4,2], val = 2,
Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length

Clarification:
Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array
will be known to the caller as well.
Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
"""


class Solution:
    def removeElement(self, nums: list, val: int) -> int:
        i, l = 0, len(nums)

        while i < l:
            if nums[i] == val:
                nums[i] = nums[l - 1]
                l -= 1
            else:
                i += 1

        return l

    def version_two(self, nums: list, val: int) -> int:
        i, j, l = 0, 0, len(nums)

        for i in range(l):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1

        return j

    def version_one(self, nums: list, val: int) -> int:
        i, f, j = 0, 0, len(nums) - 1

        if j < 0:
            return 0

        while i < j:
            success = True
            while nums[i] == val:
                if i == j:
                    success = False
                    break

                # swap current ele with last ele
                temp = nums[i]
                nums[i] = nums[j]
                nums[j] = temp
                j -= 1

            if success:
                f += 1
            i += 1

        if nums[i] == val:
            return f
        return f + 1


s = Solution()
l = [4, 3, 4, 3, 4]
index = s.removeElement(l, 3)
print(l, index)
