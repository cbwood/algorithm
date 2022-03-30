/*
 *@File Name          :leetcode-76.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/30 9:45
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mt;
        map<char, int> ms;
        string ans = "";
        for (auto &x: t)
            mt[x]++;
        int l = 0, r = 0;
        int n = s.size();
        int m = t.size();
        if (m > n) return ans;
        int num = 0;
        while (r < n) {
            ms[s[r]]++;
            if (ms[s[r]] <= mt[s[r]]) num++;
            r++;
            while (num == m && ms[s[l]] > mt[s[l]]) {
                ms[s[l]]--;
                l++;
            }
            if (num == m && (r - l < ans.length() || ans.empty())) {
                ans = s.substr(l, r - l);;
            }
        }
        return ans;
    }
};