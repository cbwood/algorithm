from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        i = 0
        lenn = len(matrix[0])
        while i <= lenn//2:
            for j in range(i, lenn-i-1):
                matrix[i][j], matrix[j][lenn-1-i], matrix[lenn-i-1][lenn-j-1], matrix[lenn-1-j][i] = matrix[lenn-1-j][i], matrix[i][j], matrix[j][lenn-1-i], matrix[lenn-i-1][lenn-j-1]
            i += 1

if __name__ == "__main__":
    so = Solution()
    b = [
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
]
    a = [[1,2,3],[4,5,6],[7,8,9]]
    so.rotate(a)
    print(a)