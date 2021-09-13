from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = nums[0]
        ans1 = nums[0]
        ans2 = nums[0]
        t = nums[1:]
        for v in t:
            q = ans1
            ans1 = max(ans1*v, max(ans2*v, v))
            ans2 = min(ans2*v, min(q*v, v))
            ans = max(ans, max(ans1, ans2))
        return ans



if __name__ == "__main__":
    so = Solution()
    print(so.maxProduct([-4,-3,-2]))