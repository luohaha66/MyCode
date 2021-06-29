/**
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，
 * 并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例 1：
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 * 示例 2：
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 * 示例 3：
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *  
 * 提示：
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int inc = 0;
    struct ListNode* head = NULL;
    struct ListNode* headMark = NULL;
    while (l1 || l2) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->next = NULL;
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        tmp->val = (n1 + n2 + inc) % 10;
        inc = (n1 + n2 + inc) / 10;
        if (head == NULL)
        {
            head = tmp;
            headMark = head;
        } else {
            head->next = tmp;
            head = tmp;
        }
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    if (inc > 0) {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        tmp->val = inc;
        tmp->next = NULL;
        head->next = tmp;
    }
    return headMark;
}

int main(void)
{
}
