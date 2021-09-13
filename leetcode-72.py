class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        dp = [[0]*(m+1) for i in range(n+1)]
        if n == 0:
            return m
        if m == 0:
            return n
        for i in range(1, m+1):
            dp[0][i] = i
        for i in range(n+1):
            dp[i][0] = i
        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
        return dp[-1][-1]

if __name__ == "__main__":
    so = Solution()
    print(so.minDistance('a', 'a'))