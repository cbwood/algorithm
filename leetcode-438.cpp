#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, s1(26,0), s2(26, 0);
        int k = p.length();
        int n = s.length();
        for(auto &x: p)
            s1[x - 'a']++;
        for (int i = 0; i < n; ++i){
            if (i >= k)
                s2[s[i-k] - 'a']--;
            s2[s[i] - 'a']++;
            if(s2 == s1)
                ans.push_back(i - k+1);
        }
            return ans;
    }
};

int main(){
    Solution so;
    vector<int> ans = so.findAnagrams("cbaebabacd", "abc");
    for(auto &x: ans)
        printf("%d ", x);
    return 0;
}