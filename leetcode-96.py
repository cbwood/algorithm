from functools import reduce

class Solution:
    def numTrees(self, n: int) -> int:
        a = reduce(lambda x,y: x*y, range(n+1,2*(n)+1))
        b = reduce(lambda x,y: x*y, range(1,n+1))
        ans = a/b/(n+1)
        return int(ans)

if __name__ == "__main__":
    so = Solution()
    ans = so.numTrees(5)
    print(ans)