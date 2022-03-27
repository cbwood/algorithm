/*
 *@File Name          :leetcode-22.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/27 9:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto &x: dp[j])
                    for (auto &y: dp[i - j - 1])
                        dp[i].emplace_back("(" + x + ")" + y);
            }
        }
        return dp[n];
    }
};


class Solution1 {
public:
    vector<string> ans;

    void dfs(int l, int r, string t, int n) {
        if (l == n && l == r) {
            ans.emplace_back(t);
            return;
        }
        if (r >= n) return;
        if (r > l) return;
        if (l > r + 2 * n - l - r) return;
        if (l < n)
            dfs(l + 1, r, t + "(", n);
        if (l > r)
            dfs(l, r + 1, t + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        dfs(0, 0, "", n);
        return ans;
    }
};