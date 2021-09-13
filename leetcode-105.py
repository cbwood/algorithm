from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        m = len(preorder)
        n = len(inorder)
        dic = dict()
        for i in range(n):
            dic[inorder[i]] = i
        def dfs(l=0,r=m-1, ll=0, rr=n-1):
            if ll > rr or l > r:
                return None
            v = preorder[l]
            u = TreeNode(v)
            k = dic[v]-ll
            u.left = dfs(l+1, l+k, ll, dic[v]-1)
            u.right = dfs(l+k+1, r, dic[v]+1, rr)
            return u
        
        return dfs()


if __name__ == "__main__":
    so = Solution()
    print(so.buildTree([3,9,20,15,7], [9,3,15,20,7]))