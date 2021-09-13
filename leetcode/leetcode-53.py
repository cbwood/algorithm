from typing import List, NamedTuple

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -1111111111111
        summ = 0
        for v in nums:
            summ += v
            ans = max(ans, summ)
            if summ < 0:
                summ = 0
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))