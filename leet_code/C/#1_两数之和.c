/**
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出和为目标值 target的那两个整数,
 * 并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 *
 * 示例 1：
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 *
 * 示例 2：
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 *
 * 示例 3：
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 *
 * 提示：
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * 只会存在一个有效答案
 *
 * 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

typedef struct test {
	int nums[64];
	int nums_size;
	int target;
	int result[2];
}test_t;

test_t tests[] = {
	{{2, 7, 11, 15}, 4, 9, {0, 1}},
	{{3, 2, 4}, 3, 6, {1, 2}},
	{{3, 3}, 2, 6, {0, 1}}
};

// * 暴力法
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i = 0, j = 0;
	for (i = 0; i < numsSize; i++) {
		int addend = target - nums[i];
		for (j = i + 1; j < numsSize; j++) {
			if (nums[j] == addend) {
				*returnSize = 2;
				int *result = calloc(1, sizeof(int) * (*returnSize));
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return NULL;
}

// * hash 法
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable = NULL;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val, ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main(void)
{
	int i = 0;
	int return_size = 2;
	int test_count = sizeof(tests) / sizeof(test_t);
	for (i = 0; i < test_count; i++) {
		test_t *test = &tests[i];
		int *r = twoSum(test->nums, test->nums_size, test->target, &return_size);
		if (0 != memcmp(r, test->result, sizeof(int) * return_size)) {
			printf("Test failed, expect [%d, %d], actual [%d, %d]\n",
			       test->result[0], test->result[1], r[0], r[1]);
		}
	}
	return 0;
}
