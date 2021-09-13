import math


class Solution:
    def numSquares(self, n: int) -> int: 
        sqr = [i**2 for i in range(1, int(math.sqrt(n))+1)]
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        for i in range(1, n+1):
            for num in sqr:
                if i < num:
                    break
                dp[i] = min(dp[i], dp[i-num]+1)

        return dp[-1]

if __name__ == "__main__":
    so = Solution()
    print(so.numSquares(12))