from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        def check(k):
            num = 0
            for i in nums:
                if i <= k:
                    num += 1
            if num > k:
                return True
            return False
        
        r = len(nums)-1
        l=1
        ans = 1
        while l <= r:
            mid = (l+r)//2
            if check(mid):
                ans = mid
                r = mid-1
            else:
                l = mid+1
        return ans




if __name__ == "__main__":
    so = Solution()
    print(so.findDuplicate([1,3,4,2,2]))