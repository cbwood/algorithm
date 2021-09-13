from typing import List, get_args

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dx = [1, -1, 0 ,0, 1, -1]
        dy = [0, 0, 1, -1, -1, 1]
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        def dfs(tx, ty):
            for i in range(4):
                fx = tx + dx[i]
                fy = ty + dy[i]
                if 0<=fx<n  and 0<=fy<m and grid[fx][fy] == '1':
                    grid[fx][fy] = '0'
                    dfs(fx, fy)
        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    grid[i][j] = '0'
                    dfs(i, j)
                    ans += 1
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.numIslands([["1","1","1"],
                        ["0","1","0"],
                        ["1","1","1"]]))