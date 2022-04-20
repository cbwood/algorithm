/*
 *@File Name          :offer2-017.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/20 11:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> cnt;
        for (auto &ch: t)
            cnt[ch]++;

        int len_s = s.size();
        int l = 0, r = 0;
        int num = 0;
        string ans = "";
        while (r < len_s) {
            if (cnt.find(s[r]) == cnt.end()) {
                r++;
            } else {
                cnt[s[r]]--;

                if (cnt[s[r]] >= 0)
                    num++;
                r++;
                while (cnt.find(s[l]) == cnt.end() || cnt[s[l]] < 0) {
                    if (cnt.find(s[l]) != cnt.end()) {
                        cnt[s[l]]++;
                        if (cnt[s[l]] > 0)
                            num--;
                    }
                    l++;
                }
            }
            if ((r - l < ans.size() || ans.size() == 0) && num >= t.size()) {
                ans = s.substr(l, r - l);
            }
        }
        return ans;
    }
};