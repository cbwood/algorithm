/*
 *@File Name          :leetcode-72.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/12 9:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0 || m == 0) return max(n, m);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= m; i++)
            dp[0][i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};