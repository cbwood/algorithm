from typing import List

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        se = dict()
        def dfs(u, step=0):
            if u is None:
                return
            if step not in se:
                se[step] = []
            se[step].append(u.val)
            dfs(u.left, step+1)
            dfs(u.right, step+1)
        dfs(root)
        ans = []
        for u in se:
            ans.append(se[u])
        return ans