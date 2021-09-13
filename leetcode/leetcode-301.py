from typing import List

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        ans = []
        numl, numr, num, q = 0, 0, 0, 0
        for u in s:
            if u == ')':
                numr += 1
            elif u == '(':
                numl += 1
            else:
                q += 1
            if numr > numl:
                num += 1
                numr -= 1
        num += abs(numr-numl)
        lens = len(s)
        def dfs(st, k, numll, numrr):
            if  numll == numrr and len(st) == lens-num:
                    ans.append(st[:])
            if k == lens:
                return
            if numrr>numll:
                return
            if numrr+lens-k < numll:
                return
            if s[k] == ')':
                dfs(st[:]+s[k], k+1, numll, numrr+1)
                dfs(st[:], k+1, numll, numrr)
            elif s[k] == '(':
                dfs(st[:]+s[k], k+1, numll+1, numrr)
                dfs(st[:], k+1, numll, numrr)
            else:
                dfs(st[:]+s[k], k+1, numll, numrr)
        dfs('', 0, 0, 0)
        ans = list(set(ans))
        return ans

if __name__ == "__main__":
    so = Solution()
    print(so.removeInvalidParentheses("n"))