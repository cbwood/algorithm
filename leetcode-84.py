from typing import List

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = [0]*n, [n]*n
        stac = list()
        for i in range(n):
            while stac and heights[stac[-1]] >= heights[i]:
                stac.pop()
            left[i] = stac[-1] if stac else -1
            stac.append(i)
        
        stac = list()
        for i in range(n-1, -1, -1):
            while stac and heights[stac[-1]] >= heights[i]:
                stac.pop()
            right[i] = stac[-1] if stac else n
            stac.append(i)

        ans = max((right[i]-left[i]-1)*heights[i] for i in range(n)) if n else 0
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.largestRectangleArea([2,1,5,6,2,3]))