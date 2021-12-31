/*
 * @File Name          :leetcode-3.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2021/12/31 9:06
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int,int> ma;
        int l = 0, r= 0;
        int n = s.size();
        while(r < n){
            ma[s[r]-'a']++;
            while(l < r && ma[s[r]-'a'] > 1){
                ma[s[l]-'a']--;
                l++;
            }ans = max(ans, r-l+1);
            r++;
        }return ans;
    }
};