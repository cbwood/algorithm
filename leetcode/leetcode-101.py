# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def dfs(p, q):
            if p is None and q is None:
                return True
            if p is None or q is None:
                return False
            return (p.val == q.val) and dfs(p.left, q.right) and dfs(p.right, q.left)
        return dfs(root, root)


if __name__ == "__main__":
    so = Solution()
    a = [1, 2]
    b = [2, 1]
    print(a==b)