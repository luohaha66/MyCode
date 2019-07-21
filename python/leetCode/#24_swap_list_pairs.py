"""
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        prev, cur = None, head

        if head and head.next:
            head = head.next

        while cur and cur.next:
            if cur.next:
                curNow, cur = cur, cur.next.next
                if prev:
                    prev.next = curNow.next
                curNow.next.next = curNow
                curNow.next = cur
                prev = curNow

        return head

    def version_one(self):
        h = ListNode(-1)
        p = h

        while head:
            if head.next:
                h.next = ListNode(head.next.val)
                h = h.next
            h.next = ListNode(head.val)
            h = h.next
            head = head.next
            if head:
                head = head.next

        return p.next


a = ListNode(1)
# b = ListNode(2)
# c = ListNode(3)
# d = ListNode(6)
# e = ListNode(8)
# a.next = b
# b.next = c
# c.next = d
# d.next = e
p = a
while p:
    print(p.val, '->', end='')
    p = p.next
print()

s = Solution()
p = s.swapPairs(a)
while p:
    print(p.val, '->', end='')
    p = p.next
print()
