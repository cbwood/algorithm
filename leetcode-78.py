from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        lenq = len(nums)
        def dfs(u, li):
            if u == lenq:
                ans.append(li[:])
                return
            dfs(u+1, li+[nums[u]])
            dfs(u+1, li)
        dfs(0, [])
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.subsets([1,2,3]))