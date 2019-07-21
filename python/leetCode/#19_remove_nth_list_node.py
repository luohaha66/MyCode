"""
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
"""


# Definition for singly-linked list.
class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # slow and fast point
        h = ListNode(0)
        h.next = head

        slow = fast = h

        while n + 1:
            fast = fast.next
            n -= 1

        while fast:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next

        return h.next


a = ListNode(1)
# b = ListNode(2)
# c = ListNode(3)
# d = ListNode(4)
# e = ListNode(5)
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
p = s.removeNthFromEnd(a, 1)
while p:
    print(p.val, '->', end='')
    p = p.next
