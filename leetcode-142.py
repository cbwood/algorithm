# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        def check():
            t1 = head
            t2 = head
            while t2 is not None and t2.next is not None:
                t1  = t1.next
                t2 = t2.next.next
                if t1 == t2:
                    return t2
            return None
        u = check()
        if u is None:
            return None
        p1 = head
        p2 = u
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next
        return p1