from typing import List

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        
        row = m-1
        col = 0
        while row >= 0 and col < n:
            if matrix[row][col] > target:
                row -= 1
            elif matrix[row][col] < target:
                col += 1
            else:
                return True
        return False

        # def search(k, check):
        #     if check:
        #         l, r = 0, n-1
        #         while l <= r:
        #             mid = (l+r)//2
        #             if matrix[k][mid] > target:
        #                 r = mid-1
        #             elif matrix[k][mid] < target:
        #                 l = mid+1
        #             else:
        #                 return True
        #         return False

        #     l, r = 0, m-1
        #     while l <= r:
        #             mid = (l+r)//2
        #             if matrix[mid][k] > target:
        #                 r = mid-1
        #             elif matrix[mid][k] < target:
        #                 l = mid+1
        #             else:
        #                 return True
        #     return False

        # t = min(n,m)
        # for i in range(t):
        #     check1 = search(i, True)
        #     check2 = search(i, False)
        #     if check1 or check2:
        #         return True
        # return False
       


if __name__ == "__main__":
    so = Solution()
    print(so.searchMatrix([[1,4],[2,5]], 5))