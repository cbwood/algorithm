/*
 *@File Name          :offer2-015.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/20 10:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> cnt_s(26, 0), cnt_p(26, 0);
        int len_s = s.size(), len_p = p.size();

        if (len_s < len_p) return {};
        vector<int> ans;

        for (int i = 0; i < len_p; ++i)
            cnt_p[p[i] - 'a']++, cnt_s[s[i] - 'a']++;

        if (cnt_p == cnt_s) ans.emplace_back(0);
        for (int i = len_p; i < len_s; i++) {
            cnt_s[s[i] - 'a']++;
            cnt_s[s[i - len_p] - 'a']--;
            if (cnt_p == cnt_s) ans.emplace_back(i - len_p + 1);
        }
        return ans;
    }
};