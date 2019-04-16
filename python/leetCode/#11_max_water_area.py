"""
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical
lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
"""


class Solution:
    def maxArea(self, height: list) -> int:
        start, end, max_area = 0, len(height) - 1, 0

        while start < end:
            if height[start] < height[end]:
                max_area = max(max_area, height[start] * (end - start))
                start += 1
            else:
                max_area = max(max_area, height[end] * (end - start))
                end -= 1
        return max_area


print(Solution().maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
