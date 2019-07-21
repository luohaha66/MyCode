"""
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Tail insertion method
        """
        k = 3
            pre
            tail    head
            dummy    1     2     3     4     5

        move tail to the last element
            pre     head       tail
            dummy    1     2     3     4     5
                   cur

        move cur to tail back in turn
            pre          tail  head
            dummy    2     3    1     4     5
                    cur
        """
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        tail = dummy

        while True:
            count = k
            while count and tail:
                count -= 1
                tail = tail.next

            if not tail:
                break
            head = pre.next
            while pre.next != tail:
                # get next
                cur = pre.next

                pre.next = cur.next
                cur.next = tail.next
                tail.next = cur

            pre = head
            tail = head

        return dummy.next

    def version_one(self, head: ListNode, k: int) -> ListNode:
        if k == 0 or k == 1:
            return head

        temp = ListNode(-1)
        dummy = temp

        while head:
            can_swap = True
            swap_items = k - 1
            p = head

            while swap_items:
                p = p.next
                swap_items -= 1
                if not p:
                    can_swap = False
                    break

            if can_swap:
                counts = k

                while counts:
                    q = head
                    swap_items = counts - 1
                    while swap_items:
                        q = q.next
                        swap_items -= 1
                    temp.next = ListNode(q.val)
                    temp = temp.next
                    counts -= 1

                counts = k
                while counts:
                    head = head.next
                    counts -= 1
            else:
                temp.next = head
                break

        return dummy.next

    def version_two(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        p = dummy

        while True:
            count = k
            stack = []
            tmp = head
            while count and tmp:
                stack.append(tmp)
                tmp = tmp.next
                count -= 1
            # can't swap
            if count:
                p.next = head
                break
            # reverse
            while stack:
                p.next = stack.pop()
                p = p.next

            head = tmp

        return dummy.next


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

s = Solution()
p = s.reverseKGroup(a, 3)
while p:
    print(p.val, '->', end='')
    p = p.next
print()
