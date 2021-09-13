from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n < 2:
            return
        i = n-2
        while i > 0 and nums[i] >= nums[i+1]:
            i -= 1
        if i == 0 and nums[i] == max(nums):
            return nums.reverse()
        j = n-1
        while j > i and nums[j] <= nums[i]:
            j -= 1
        nums[j], nums[i] = nums[i], nums[j]
        for k in range(i+1, (n+i+1)//2):
            nums[k], nums[n+i-k] = nums[n+i-k], nums[k]


if __name__ == "__main__":
    so = Solution()
    nums = [2, 5, 3,1]
    so.nextPermutation(nums)
    print(nums)
