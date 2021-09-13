from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def dfs(u):
            if u is None:
                return
            dfs(u.left)
            ans.append(u.val)
            dfs(u.right)
        dfs(root)
        return ans


if __name__ == "__main__":
    so = Solution()
