from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minx = int(1e9)
        ans = 0
        for v in prices:
            ans = max(ans, v-minx)
            minx = min(v, minx)
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.maxProfit([7,1,5,3,6,4]))