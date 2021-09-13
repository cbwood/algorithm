# -*- coding:utf-8 -*-
from typing import AnyStr


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        if pHead is None:
            return None
        ans = ListNode(pHead.val)
        pHead = pHead.next
        while pHead:
            tmp = ListNode(pHead.val)
            tmp.next = ans
            ans = tmp
            pHead = pHead.next
        return ans