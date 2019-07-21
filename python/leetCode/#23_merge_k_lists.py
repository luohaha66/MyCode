"""
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its comlist1lexity.

Examlist1le:
Inlist1ut:
[
  1->4->5,
  1->3->4,
  2->6
]
Outlist1ut: 1->1->2->3->4->4->5->6
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists: list) -> list:
        if not lists:
            return []
        n = len(lists)
        return self.merge(lists, 0, n - 1)

    def merge(self, lists, left, right):
        if left == right:
            return lists[left]
        mid = left + (right - left) // 2
        l1 = self.merge(lists, left, mid)
        l2 = self.merge(lists, mid + 1, right)
        return self.mergeTwoLists(l1, l2)

    def mergeTwoLists(self, l1, l2):
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

    def version_one(self, lists: list):
        import heapq

        dummy = ListNode(0)
        p = dummy
        head = []
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(head, (lists[i].val, i))
                lists[i] = lists[i].next
        while head:
            val, idx = heapq.heappop(head)
            p.next = ListNode(val)
            p = p.next
            if lists[idx]:
                heapq.heappush(head, (lists[idx].val, idx))
                lists[idx] = lists[idx].next
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

j = ListNode(2)
k = ListNode(6)
l = ListNode(9)
j.next = k
k.next = l
p = j
while p:
    print(p.val, '->', end='')
    p = p.next
print()

lists = [a, f, j]
s = Solution()
p = s.mergeTwoLists(a, f)
while p:
    print(p.val, '->', end='')
    p = p.next
print()
