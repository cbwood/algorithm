import functools
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) <= 0:
            return []
        def cmp(a, b):
            if a[0] == b[0]:
                return -1 if a[1] <= b[1] else 1
            return -1 if a[0] <= b[0] else 1
        intervals = sorted(intervals, key = functools.cmp_to_key(cmp))
        ans = []
        l = intervals[0][0]
        r = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] > r:
                ans.append([l, r])
                l = intervals[i][0]
                r = intervals[i][1]
            r = max(r, intervals[i][1])
        ans.append([l, r])
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.merge([[1,4],[0,4]]))