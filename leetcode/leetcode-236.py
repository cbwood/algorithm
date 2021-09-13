# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = root
        def dfs(u):
            if u is None:
                return False
            cur = u ==p or u == q
            le = dfs(u.left)
            re = dfs(u.right)
            if (le and re ) or (cur and (le or re)):
                self.ans = u
            return le or re or cur
        dfs(root)
        return self.ans