from typing import List
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        k = len(lists)
        head = []
        for i in range(k):
            if lists[i]:
                heapq.heappush(head, (lists[i].val, i))
                lists[i] = lists[i].next
        ans = ListNode(0)
        que = ans
        while head:
            v , i = heapq.heappop(head)
            que.next = ListNode(v)
            que = que.next
            if lists[i]:
                heapq.heappush(head, (lists[i].val, i))
                lists[i] = lists[i].next
        return ans.next
        # flag = True
        # u = -1
        # v = 1000000000
        # for i in range(k):
        #     if lists[i] is not None:
        #         if v > lists[i].val:
        #             u = i
        #             v = lists[i].val
        # if u != -1:
        #     ans = ListNode(v)
        #     lists[u] = lists[u].next
        # else:
        #     return None
        # que = ans
        # while flag:
        #     u = -1
        #     v = 1000000000
        #     for i in range(k):
        #         if lists[i] is not None:
        #             if v > lists[i].val:
        #                 u = i
        #                 v = lists[i].val
        #     if u == -1:
        #         break
        #     t = ListNode(v)
        #     lists[u] = lists[u].next
        #     que.next = t
        #     que = que.next
        # return ans

if __name__ == "__main__":
    q = [[1,4,5],[1,3,4],[2,6]]
    so = Solution()
    li = []
    a = ListNode(1)
    b = ListNode(4)
    c = ListNode(5)
    a.next = b
    b.next = c
    li.append(a)
    a = ListNode(1)
    b = ListNode(3)
    c = ListNode(4)
    a.next = b
    b.next = c
    li.append(a)
    a = ListNode(2)
    b = ListNode(6)
    a.next = b
    li.append(a)
    ans = so.mergeKLists(li)
    while ans:
        print(ans.val, end=' ')
        ans = ans.next