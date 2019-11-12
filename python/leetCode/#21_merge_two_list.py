"""
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        p = l1
        q = l2
        merge = ListNode(0)
        head = merge

        while p and q:
            if p.val > q.val:
                merge.next = q
                q = q.next
            else:
                merge.next = p
                p = p.next
            merge = merge.next

        if p:
            merge.next = p
        else:
            merge.next = q

        return head.next


a = ListNode(1)
b = ListNode(2)
c = ListNode(3)
d = ListNode(6)
e = ListNode(8)
a.next = b
b.next = c
c.next = d
d.next = e
p = a
while p:
    print(p.val, '->', end='')
    p = p.next
print()

f = ListNode(1)
g = ListNode(4)
h = ListNode(5)
i = ListNode(6)
j = ListNode(7)
f.next = g
g.next = h
h.next = i
i.next = j
p = f
while p:
    print(p.val, '->', end='')
    p = p.next
print()

s = Solution()
p = s.mergeTwoLists(a, f)
while p:
    print(p.val, '->', end='')
    p = p.next
print()
