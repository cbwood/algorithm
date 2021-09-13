# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        tail = head
        pre = head
        ans = pre
        tmp = head
        while tail:
            while tail.next and tail.next.next:
                tmp = tail.next
            tmp.next = pre.next.next
            pre.next = tmp
        return ans