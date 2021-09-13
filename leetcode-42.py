from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        le = 0
        re = len(height)-1
        lmax = 0
        rmax = 0
        while le < re:
            if height[le] <= height[re]:
                if height[le] >= lmax:
                    lmax = height[le]
                else:
                    ans += lmax - height[le]
                le += 1
            else:
                if height[re] >= rmax:
                    rmax = height[re]
                else:
                    ans += rmax - height[re]
                re -= 1
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.trap([0,1,0,2,1,0,1,3,2,1,2,1]))