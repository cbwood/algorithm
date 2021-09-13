from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        dic = dict()
        for v in nums:
            if v in dic:
                continue
            dic[v] = 1
            lv = dic.get(v-1, 0)
            rv = dic.get(v+1, 0)
            vv = lv+rv+1
            ans = max(ans, vv)
            dic[v-lv] = vv
            dic[v+rv] = vv
        return ans

            


if __name__ == "__main__":
    so = Solution()
    print(so.longestConsecutive([100, 4, 200, 1, 3, 2]))