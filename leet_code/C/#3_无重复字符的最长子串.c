/**
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 示例 1:
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 * 示例 2:
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 * 示例 3:
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 *      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 * 示例 4:
 * 输入: s = ""
 * 输出: 0
 *
 * 提示：
 * 0 <= s.length <= 5 * 104
 * s 由英文字母、数字、符号和空格组成
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable = NULL;

struct hashTable* find(int ikey)
{
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival)
{
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

void remove_all() {
	struct hashTable *cur, *tmp;
	HASH_ITER(hh, hashtable, cur, tmp) {
		HASH_DEL(hashtable, cur);
		free(cur);
	}
}

// int lengthOfLongestSubstring(char *s)
// {
// 	int len = strlen(s);
// 	int max_sub = 0, tmp = 0, i = 0, start = 0;
// 	hashtable = NULL;
// 	for (i = 0; i < len; i++) {
// 		struct hashTable *it = find(s[i]);
// 		if (it && (start <= it->val))
// 			start = it->val + 1;
// 		else
// 			max_sub = max_sub > i - start + 1 ? max_sub : i - start + 1;

// 	}
// 	return max_sub;
// }

int lengthOfLongestSubstring(char * s)
{
    int res = 0;
    int len = strlen(s);
    /* 存储 ASCII 字符在子串中出现的次数 */
    int freq[256] = {0};
    /* 定义滑动窗口为 s[l...r] */
    int l = 0, r = -1;
    while (l < len) {
        /* freq 中不存在该字符，右边界右移，并将该字符出现的次数记录在 freq 中 */
        if (r < len - 1 && freq[s[r + 1]] == 0) {
            freq[s[++r]]++;
        /* 右边界无法拓展，左边界右移，刨除重复元素，并将此时左边界对应的字符出现的次数在 freq 的记录中减一 */
        } else {
            freq[s[l++]]--;
        }
        /* 当前子串的长度和已找到的最长子串的长度取最大值 */
        res = res > r - l + 1 ? res : r - l + 1;
    }

    return res;
}

int main()
{
	printf("max_sub: %d\n", lengthOfLongestSubstring("abcabcbb"));
	printf("max_sub: %d\n", lengthOfLongestSubstring("bbbbb"));
	printf("max_sub: %d\n", lengthOfLongestSubstring("pwwkew"));
	printf("max_sub: %d\n", lengthOfLongestSubstring(""));
	printf("max_sub: %d\n", lengthOfLongestSubstring("dvdf"));
}
