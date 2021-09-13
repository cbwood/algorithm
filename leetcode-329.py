from typing import List
from functools import lru_cache

class Solution:

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if len(matrix) == 0:
            return 0
        m = len(matrix[0])
        n = len(matrix)
        dp =[[-1]*m for i in range(n)]
        ans = 1
        dx = [1,-1,0,0]
        dy = [0, 0,1,-1]
        @lru_cache(None)
        def dfs( i, j):
            if dp[i][j] != -1:
                return dp[i][j]
            dp[i][j] = 1
            for nn in range(4):
                di = i + dx[nn]
                dj = j + dy[nn]
                if 0<= di<n and 0<=dj<m and matrix[i][j] < matrix[di][dj]:
                    dp[i][j] = max(dp[i][j], dfs(di, dj)+1)
            return dp[i][j]
        for i in range(n):
            for j in range(m):
                ans = max(ans, dfs(i, j))
        return ans


if __name__ == "__main__":
    so = Solution()
    nums = [
            [9,9,4],
            [6,6,8],
            [2,1,1]
            ] 
    print(so.longestIncreasingPath(nums))