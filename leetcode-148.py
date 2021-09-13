# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        n = 0
        u = head
        while u:
            u = u.next
            n += 1
        def merge(n, u):
            if n <= 1:
                return u
            if n == 2:
                p = u.next
                if p.val > u.val:
                    p.next = u
                    u.next = None
                    return p
                return u
            k = 0
            t = u
            while k <= n//2:
                k += 1
                t = t.next
            k = merge(n//2, u)
            p = merge(n-n//2, t)
            q = ListNode(1)
            ans = q
            while k is not None and p is not None:
                if k.val < p.val:
                    q.next = k
                    k = k.next
                else:
                    q.next = p
                    p = p.next
                q = q.next
            while k is not None:
                q.next = k
                k = k.next
                q = q.next
            while p is not None:
                q.next = p
                p = p.next
                q = q.next
            return ans.next
        return merge(n, head)