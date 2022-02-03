/*
 * @File Name          :leetcode-5-1.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/2 9:18
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        int ans = 1;
        int l = 0, r = 0;

        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++) {
                if (j == i + 1) {
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                } else {
                    if (dp[i + 1][j - 1] && s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    l = i;
                    r = j;
                }
            }
        return s.substr(l, r - l + 1);
    }
};