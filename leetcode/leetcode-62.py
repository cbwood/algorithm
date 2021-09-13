from typing import List

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # dp = [1 for i in range(n)]
        # for i in range(1, m):
        #     for j in range(1, n):
        #         dp[j] = dp[j-1]+dp[j]
        # return dp[n-1]
        def fi(n, m):
            ans = 1
            while m > 0:
                ans *= n
                n -= 1
                m -= 1
            return ans
        a = m+n-2
        b = m-1
        ans = fi(a, b)//(fi(b,b))
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.uniquePaths(3,2))