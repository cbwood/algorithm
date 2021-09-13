from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lenq = len(nums)
        maxi = 0
        for i in range(lenq):
            if i > maxi:
                return False
            maxi = max(maxi, i+nums[i])
        return True


if __name__ == "__main__":
    so = Solution()
    print(so.canJump([3,2,1,0,4]))