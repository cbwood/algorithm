/*
 *@File Name          :offer2-016.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/20 10:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len_s = s.size();
        int ans = 0;
        int l = 0, r = 0;
        unordered_map<char, int> cnt;
        while (r < len_s) {
            cnt[s[r]]++;
            while (cnt[s[l]] > 1 || cnt[s[r]] > 1) {
                cnt[s[l]]--;
                l++;
            }
            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};