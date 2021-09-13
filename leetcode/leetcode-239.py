from typing import List
import collections

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        que = collections.deque()
        l,r = 0, 0
        ans = []
        while r < k:
            while que and nums[r] >= nums[que[-1]]:
                que.pop()
            que.append(r)
            r += 1
        lenq = len(nums)
        while r < lenq:
            while que and que[0] < l:
                que.popleft()
            if que:
                ans.append(nums[que[0]])
            while que and nums[r] >= nums[que[-1]]:
                que.pop()
            que.append(r)
            l += 1
            r += 1
        while que and que[0] < l:
            que.popleft()
        ans.append(nums[que[0]])
        return ans




if __name__ == "__main__":
    so = Solution()
    print(so.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))