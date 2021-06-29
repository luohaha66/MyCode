"""
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ptr1 = l1
        ptr2 = l2
        l3 = ListNode(0)
        ptr3 = l3
        carry_bit = 0
        while ptr1 or ptr2:
            if not ptr1:
                new_val = ptr2.val + carry_bit
                ptr2 = ptr2.next
            elif not ptr2:
                new_val = ptr1.val + carry_bit
                ptr1 = ptr1.next
            else:
                new_val = ptr1.val + ptr2.val + carry_bit
                ptr1 = ptr1.next
                ptr2 = ptr2.next
            carry_bit = new_val // 10
            new_val %= 10
            new_node = ListNode(new_val)
            ptr3.next = new_node
            ptr3 = ptr3.next
        if carry_bit != 0:
            ptr3.next = ListNode(carry_bit)
        return l3.next

    def addTwoNumbers1(self, l1: ListNode, l2: ListNode) -> ListNode:
	    pre = ListNode(0)
        cur = pre
        b = 0

        while l1 or l2:
            s = 0
            if l1:
                s += l1.val
                l1 = l1.next
            if l2:
                s += l2.val
                l2 = l2.next
            s += b
            cur.next = ListNode(s%10)
            cur = cur.next
            b = s//10

        if b!=0:
            cur.next = ListNode(1)
        return pre.next
