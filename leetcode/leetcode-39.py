from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        li = []
        candidates.sort()
        def dfs(summ, u):
            if summ == target:
                ans.append(li[:])
                return
            for i in range(u, len(candidates)):
                if summ + candidates[i] > target:
                    return
                li.append(candidates[i])
                dfs(summ+candidates[i], i)
                li.remove(candidates[i])
        dfs(0, 0)
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.combinationSum([2,3,6,7], 7))