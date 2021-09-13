class Solution:
    def climbStairs(self, n: int) -> int:
        a = 1
        b = 1
        while n:
            n -= 1
            a,b = a+b, a
        return b

if __name__ == "__main__":
    so = Solution()
    print(so.climbStairs(3))