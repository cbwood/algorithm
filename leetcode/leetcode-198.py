from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        dp = [0]*n
        ans = 0
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = nums[0]+nums[2]
        ans = max(dp[0], dp[1])
        ans = max(ans, dp[2])
        for i in range(3,n):
            dp[i] = max(dp[i-2], dp[i-3])+nums[i]
            ans = max(ans, dp[i])
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.rob([2,7,9,3,1]))