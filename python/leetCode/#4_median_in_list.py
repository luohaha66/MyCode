"""
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
"""


class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        # method one cost time: 0:00:12.648189
        nums1.extend(nums2)
        nums1.sort()
        list_len = len(nums1)
        center = list_len // 2
        if list_len % 2 == 0:
            return float((nums1[center] + nums1[center - 1]) / 2)
        return float(nums1[center])

        # method one cost time: 0:00:00.559505
        # condition:
        # nums2[j−1] ≤ nums1[i] and nums1[i-1] ≤ nums2[j], j = (m + n + 1) / 2 - i

        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        if n == 0:
            raise ValueError

        imin, imax, half_len = 0, m, (m + n + 1) // 2

        while imin <= imax:
            # at first, left part equal to right part
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and nums2[j - 1] > nums1[i]:
                # i is too small, must increase it
                imin = i + 1
            elif i > 0 and nums1[i - 1] > nums2[j]:
                # i is too big, must decrease it
                imax = i - 1
            else:
                # i is perfect
                if i == 0:
                    max_of_left = nums2[j - 1]
                elif j == 0:
                    max_of_left = nums1[i - 1]
                else:
                    max_of_left = max(nums1[i - 1], nums2[j - 1])

                if (m + n) % 2 == 1:
                    return max_of_left

                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])

                return (max_of_left + min_of_right) / 2.0


import datetime
a = datetime.datetime.now()
num1 = [each for each in range(10)] * 10000000
num2 = [each for each in range(0, 20, 2)] * 10000000
print(Solution().findMedianSortedArrays(num1, num2))
print('cost: ', datetime.datetime.now() - a)
