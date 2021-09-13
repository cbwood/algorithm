# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def reverse(u):
            if u is None:
                return
            u.left, u.right = u.right, u.left
            reverse(u.left)
            reverse(u.right)
        reverse(root)
        return root