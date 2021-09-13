class Solution:
    def minWindow(self, s: str, t: str) -> str:
        se = dict()
        sq = dict()
        for c in t:
            if c not in se:
                se[c] = 0
            se[c] += 1
        def check():
            for c in se:
                if c not in sq or se[c] > sq[c]:
                    return False
            return True
        l = 0
        ansl = -1
        len1 = 999999
        for i in range(len(s)):
            if s[i] not in sq:
                sq[s[i]] = 0
            sq[s[i]] += 1
            while check() and l <= i:
                if len1 > i-l+1:
                    len1 = i-l+1
                    ansl = l
                sq[s[l]] -= 1
                l += 1

        return '' if ansl == -1 else s[ansl: ansl+len1]


if __name__ == "__main__":
    so = Solution()
    print(so.minWindow('ab', 'a'))