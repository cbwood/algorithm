from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        idx = -1
        l = 0
        r = len(nums)-1
        if r < 0:
            return idx
        while l <= r:
            mid = (l+r)//2
            print(l,r,mid, nums[mid])
            if nums[mid] == target:
                idx = mid
                break
            if nums[0] <= nums[mid]:
                if nums[0] <= target <= nums[mid]:
                    r = mid-1
                else:
                    l = mid+1
            else:
                if nums[mid] <= target <= nums[len(nums)-1]:
                    l = mid+1
                else:
                    r = mid-1
        return idx


if __name__ == "__main__":
    so = Solution()
    print(so.search([4,5,6,7,8,1,2,3], 8))