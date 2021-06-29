/**
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 请你找出并返回这两个正序数组的 中位数 。
 *
 * 示例 1：
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 * 示例 2：
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 * 示例 3：
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 *
 * 示例 4：
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 *
 * 示例 5：
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 *  
 *
 * 提示：
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -106 <= nums1[i], nums2[i] <= 106
 *  
 *
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 */
#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int total = nums1Size + nums2Size;
	int *array = malloc(total * sizeof(int));

	int i = 0, j = 0, k = 0;
	for (k = 0; k < total; k++) {
		if ((i < nums1Size) && (j < nums2Size)) {
			if (nums1[i] < nums2[j])
				array[k] = nums1[i++];
			else
				array[k] = nums2[j++];
		} else {
			if (i < nums1Size)
				array[k] = nums1[i++];
			else
				array[k] = nums2[j++];
		}
	}

	for (i = 0; i < k; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	if (total % 2 == 0)
		return (double)(array[total/2] + array[total/2-1]) / 2.0;
	else
		return (double)(array[total/2]);
}

int main(void) {
	int a[] = {1, 3};
	int b[] = {2};
	printf("%f \n", findMedianSortedArrays(a, 2, b, 1));
}
