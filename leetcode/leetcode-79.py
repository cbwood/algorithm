from typing import List
from functools import lru_cache

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        vis = [[True]*m for i in range(n)]
        @lru_cache
        def dfs(i, j, st):
            if st == word:
                return True
            if st != word[:len(st)]:
                return False
            if len(st) >= len(word):
                return False
            for k in range(4):
                tx = i + dx[k]
                ty = j + dy[k]
                if -1 < tx < n and -1 < ty < m and vis[tx][ty]:
                    vis[tx][ty] = False
                    if dfs(tx, ty, st+board[tx][ty]):
                        return True
                    vis[tx][ty] = True
           
            return False

        for i in range(n):
            for j in range(m):
                vis[i][j] = False
                if dfs(i, j, board[i][j]):
                    return True
                vis[i][j] = True

        return False


if __name__ == "__main__":
    so = Solution()
    print(so.exist([["a","a","a","a"],["a","a","a","a"],["a","a","a","a"]], "aaaaaaaaaaaaa"))