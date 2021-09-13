# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    ans = 0
    def maxDepth(self, root: TreeNode) -> int:
        def dfs(u, step=1):
            if u is None:
                return
            self.ans = max(self.ans, step)
            dfs(u.left, step+1)
            dfs(u.right, step+1)
        dfs(root)
        return self.ans
