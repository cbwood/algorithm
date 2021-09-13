from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def nextPermutation(numss: List[int]) -> None:
            """
            Do not return anything, modify numss in-place instead.
            """
            n = len(numss)
            if n < 2:
                return
            i = n-2
            while i > 0 and numss[i] >= numss[i+1]:
                i -= 1
            if i == 0 and numss[i] == max(numss):
                return numss.reverse()
            j = n-1
            while j > i and numss[j] <= numss[i]:
                j -= 1
            numss[j], numss[i] = numss[i], numss[j]
            for k in range(i+1, (n+i+1)//2):
                numss[k], numss[n+i-k] = numss[n+i-k], numss[k]
        ans = []
        ans.append(nums[:])
        li = nums[:]
        while True:
            nextPermutation(nums)
            if li == nums:
                break
            ans.append(nums[:])
        return ans

if __name__ == "__main__":
    so =Solution()
    print(so.permute([1,2,3]))