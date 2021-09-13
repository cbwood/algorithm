from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        cur = 0
        r = len(nums)-1
        while cur <= r:
            if nums[cur] == 0:
                nums[cur], nums[l] = nums[l], nums[cur]
                cur += 1
                l += 1
            elif nums[cur] == 2:
                nums[cur], nums[r] = nums[r], nums[cur]
                r -= 1
            else:
                cur += 1

if __name__ == "__main__":
    so = Solution()
    print(so.sortColors([2,0,2,1,1,0]))