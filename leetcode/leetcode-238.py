from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [0]*len(nums)
        presum = [0]*len(nums)
        presum[0] = nums[0]
        for i in range(1, len(nums)):
            presum[i] = presum[i-1]*nums[i]
        orsum = 1
        for i in range(len(nums)-1, -1, -1):
            if i == 0:
                ans[i] = orsum
            else:
                ans[i] = orsum * presum[i-1]
            orsum = orsum * nums[i]
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.productExceptSelf([1,2,3,4]))