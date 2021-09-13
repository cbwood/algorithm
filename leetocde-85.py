from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        '''
        if matrix == []:
            return 0
        def largestRectangleArea(heights: List[int]) -> int:
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
        
        n = len(matrix)
        m = len(matrix[0])
        dp = [0]*m
        ans = 0
        for i in range(n-1, -1, -1):
            for j in range(m):
                if matrix[i][j] == '1':
                    dp[j] += 1
                else:
                    dp[j] = 0
            ans = max(ans, largestRectangleArea(dp))
        '''
        if not matrix:
            return 0
        n = len(matrix)
        m = len(matrix[0])
        le, re, he = [0]*m, [m]*m, [0]*m
        ans = 0
        for i in range(n):
            lm , rm = 0, m
            for j in range(m):
                if matrix[i][j] == '1':
                    he[j] += 1
                    le[j] = max(le[j], lm)
                else:
                    he[j] = 0
                    le[j] = 0
                    lm = j+1
            for j in range(m-1, -1, -1):
                if matrix[i][j] == '1':
                    re[j] = min(re[j], rm)
                else:
                    rm = j
                    re[j] = m
                ans = max(ans, he[j]*(re[j]-le[j]))
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))