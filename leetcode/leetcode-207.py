from typing import List
import queue
import collections

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        edge = collections.defaultdict(list)
        deg = [0]*numCourses
        num = 0
        que = queue.Queue()
        for v in prerequisites:
            edge[v[1]].append(v[0])
            deg[v[0]] += 1
        for u in range(numCourses):
            if deg[u] == 0:
                que.put(u)
        while not que.empty():
            t = que.get()
            num += 1
            for u in edge[t]:
                deg[u] -= 1
                if deg[u] == 0:
                    que.put(u)
        return numCourses == num


if __name__ == "__main__":
    so = Solution()
    print(so.canFinish(2, [[1,0],[0,1]]))