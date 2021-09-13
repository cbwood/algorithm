from typing import List

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 0
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        dp = [[0]*m for i in range(n)]
        for i in range(n):
            if matrix[i][0] == '1':
                dp[i][0] = 1
                ans = 1
        for i in range(m):
            if matrix[0][i] == '1':
                dp[0][i] = 1
                ans = 1
        
        for i in range(1,n):
            for j in range(1,m):
                if matrix[i][j] == '1' :
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1
                    ans = max(ans, dp[i][j])
        return ans*ans

if __name__ == "__main__":
    so = Solution()
    print(so.maximalSquare([["0","0","0","1"],["1","1","0","1"],["1","1","1","1"],["0","1","1","1"],["0","1","1","1"]]))