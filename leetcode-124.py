# Definition for a binary tree node.
from typing import AnyStr


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    ans = -int(1e9)
    def maxPathSum(self, root: TreeNode) -> int:
        def dfs(u):
            if u is None:
                return 0
            lv = max(0, dfs(u.left))
            rv = max(0, dfs(u.right))
            self.ans = max(self.ans, lv+u.val+rv)
            return u.val+max(lv, rv)
        dfs(root)
        return self.ans