from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid[0])
        n = len(grid)
        dp = [ [9999999]*m for i in range(n)]
        for i in range(n):
            dp[i][0] = grid[i][0]
            if i > 0:
                dp[i][0] += dp[i-1][0]
        for i in range(m):
            dp[0][i] = grid[0][i]
            if i > 0:
                dp[0][i] += dp[0][i-1]

        for i in range(1,n):
            for j in range(1,m):
                dp[i][j] = grid[i][j]+min(dp[i-1][j], dp[i][j-1])
        return dp[n-1][m-1]
    

if __name__ == "__main__":
    so = Solution()
    print(so.minPathSum([[1,3,1],[1,5,1],[4,2,1]]))