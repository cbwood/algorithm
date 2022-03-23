/*
 *@File Name          :leetcode-151.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:49
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.size() - 1;
        int r = n, l = n;
        while (l >= 0) {
            if (s[l] == ' ') {
                if (r > l) {
                    if (!ans.empty())
                        ans += " ";
                    ans += s.substr(l + 1, r - l);
                }
                r = l - 1;
                l--;
            } else {
                l--;
            }
        }
        if (r > l) {
            if (!ans.empty())
                ans += " ";
            ans += s.substr(l + 1, r - l);
        }
        return ans;
    }
};