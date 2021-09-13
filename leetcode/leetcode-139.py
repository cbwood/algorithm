from typing import List

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = sorted(wordDict, key=lambda x:len(x), reverse=True)
        n = len(wordDict)
        m = len(s)
        se = dict()
        def dfs(st=''):
            if st == s:
                return True
            if len(st) >= m:
                return False
            if st in se:
                return False
            for i in range(n):
                q = st + wordDict[i]
                k = len(q)
                if q == s[:k]:
                    if dfs(q[:]):
                        return True
                    else:
                        se[q[:]] = 1
            return False
        return dfs()


if __name__ == "__main__":
    so = Solution()
    print(so.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]))