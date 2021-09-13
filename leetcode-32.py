class Solution:
    def longestValidParentheses(self, s: str) -> int:
        len1 = len(s)
        if len1 == 0:
            return 0
        dp = [0] *len1
        for i in range(1, len1):
            if s[i] == ')':
                if s[i-1] == '(':
                    if i == 1:
                        dp[i] = 2
                    else:
                        dp[i] = dp[i-2] + 2
                elif i-dp[i-1] > 0 and s[i-dp[i-1]-1] == '(':
                    if i - dp[i-1] > 1:
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
                    else:
                        dp[i] = dp[i-1] + 2
        ans = max(dp)
        return ans

if __name__ == "__main__":
    so = Solution()
    s = ')()())'
    print(so.longestValidParentheses(s))