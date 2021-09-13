# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        dic = dict()
        def dfs(u):
            if u == None:
                return False
            if u in dic:
                return True
            dic[u] = 1
            if not dfs(u.next):
                return True
            return False
        return dfs(head)