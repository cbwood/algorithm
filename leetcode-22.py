from typing import List

class Solution:

    def generate(self, n):
        if n == 0:
            return ['']
        ans = []
        for i in range(n):
            for l in self.generate(i):
                for r in self.generate(n-i-1):
                    ans.append('({}){}'.format(l, r))
        return ans
        
    def dfs(self, st, numl, numr, num):
        if num == 0:
            if numl == numr:
                self.li.append(st)
            return 
        if numl > numr + num:
            return 
        if numl >= numr:
            if numl > numr:
                self.dfs(st +')', numl, numr+1, num-1)
            self.dfs(st +'(', numl+1, numr, num-1)

    def generateParenthesis(self, n: int) -> List[str]:
        self.li = []
        self.dfs('' ,0 ,0, n*2)
        return self.li
        return self.generate(n)

if __name__ == "__main__":
    so = Solution()
    st = so.generateParenthesis(5)
    print(st)