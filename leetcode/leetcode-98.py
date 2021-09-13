# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def dfs(u, l=float('-inf'), r=float('inf')):
            if u is None:
                return True
            v = u.val
            if v > r or v < l:
                return False
            if not dfs(u.right, v, r):
                return False
            if not dfs(u.left, l, v):
                return False
            return True
        return dfs(root)