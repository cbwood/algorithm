from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def lower_bound():
            l = 0
            r = len(nums)-1
            if r < 0:
                return -1
            while l <= r:
                mid = (l+r)//2
                if target > nums[mid]:
                    l = mid+1
                else:
                    r = mid-1
            return l if 0<=l<len(nums) and nums[l] == target else -1
        def upper_bound():
            l = 0
            r = len(nums)-1
            if r < 0:
                return -1
            while l <= r:
                mid = (l+r)//2
                if target >= nums[mid]:
                    l = mid+1
                else:
                    r = mid-1
            return r if 0 <=r< len(nums)  and nums[r] == target else -1
        ans = [lower_bound(), upper_bound()]
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.searchRange([2, 2], 3))