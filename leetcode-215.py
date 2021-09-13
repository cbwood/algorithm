from  typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        k = -k
        return nums[k]


if __name__ == "__main__":
    so = Solution()
    print(so.findKthLargest([3,2,1,5,6,4], 2))