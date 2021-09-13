class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        m = len(key)
        n = len(ring)
        dic = dict()
        for i, x in enumerate(ring):
            if x not in dic:
                dic[x] = [i]
            else:
                dic[x].append(i)
        dp = [[-1]*n for i in range(m)]
        def dfs(a=0, b=0, step=0):
            if a == m:
                return 0
            if dp[a][b] != -1:
                return dp[a][b]
            tmp = 10000000
            for x in dic[key[a]]:
                t = min(abs(x-b+n)%n, abs(b-x+n)%n)
                tmp = min(tmp, t+dfs(a+1, x)+1)
            dp[a][b] = tmp
            return tmp

        return dfs()

if __name__ == "__main__":
    so = Solution()
    print(so.findRotateSteps("nyngl", "yyynnnnnnlllggg"))