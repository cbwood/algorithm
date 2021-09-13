from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = {}
        for s in strs:
            q = sorted(s)
            q = ''.join(q)
            if q not in dic:
                dic[q] = []
            dic[q].append(s)
        ans = []
        for v in dic.values():
            ans.append(v)
        return ans


if __name__ == "__main__":
    so = Solution()
    print(so.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))