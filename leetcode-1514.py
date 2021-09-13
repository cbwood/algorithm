from typing import List
import queue

'''
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        v = [[]for i in range(n)]
        maxp = 0
        for t,p in zip(edges, succProb):
            v[t[0]].append([t[1], p])
            v[t[1]].append([t[0], p])
            maxp = max(maxp, p)
        vis = [0 for i in range(n)]
        dp = [0 for i in range(n)]
        self.ans = 0
        def dfs(self, u, p):
            if u == end:
                self.ans = max(self.ans, p)
                return 
            if p < 0.0001 or self.ans > p*maxp:
                return
            for t in v[u]:
                if vis[t[0]] == 0:
                    vis[t[0]] = 1
                    dfs(self, t[0], p*t[1])
                    vis[t[0]] = 0
        vis[start] = 1
        dfs(self, start, 1)
        return self.ans

'''

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        v = [[]for i in range(n)]
        for t,p in zip(edges, succProb):
            v[t[0]].append([t[1], p])
            v[t[1]].append([t[0], p])
        def bfs():
            vis = [0 for i in range(n)]
            que = que = queue.PriorityQueue()
            que.put((-1, start))
            vis[start] = 1
            while not que.empty():
                p, u = que.get()
                p = -p
                if u == end:
                    return p
                vis[u] = 1
                for up in v[u]:
                    uu = up[0]
                    pp = up[1]
                    if vis[uu] == 0:
                        que.put((-1*pp*p, uu))
            return 0
        return bfs()


if __name__ == "__main__":
    so = Solution()
    n = 3
    a = [[0,1],[1,2],[0,2]]
    b = [0.5,0.5,0.2]
    c = 0
    d = 2
    ans = so.maxProbability(n, a, b, c, d)
    print(ans)