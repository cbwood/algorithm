/*
 *@File Name          :offer2-020.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 10:27
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
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < 2 * n - 1; i++) {
            int l = i / 2, r = i / 2 + (i & 1);
            while (l >= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        int ans = n;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                dp[i - 1][i] = 1;
                ans++;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 2; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};