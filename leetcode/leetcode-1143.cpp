/*
 *@File Name          :leetcode-1143.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/26 21:02
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
    vector<vector<int>> dp;

    int dfs(string &s1, string &s2, int i, int j) {
        if (i == s1.size() || j == s2.size())
            return 0;
        if (s1[i] == s2[j]) { dp[i][j] = 1 + dfs(s1, s2, i + 1, j + 1); }
        else {
            dp[i][j] = max(dfs(s1, s2, i, j + 1), dfs(s1, s2, i + 1, j));
        }
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return dfs(text1, text2, 0, 0);
    }
};

//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        int n = text1.size();
//        int m = text2.size();
//        int ans = 0;
//        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
//        for(int i = 0; i < n; i++)
//            for(int j = 0; j < m; j++){
//                if(text1[i] == text2[j]){
//                    dp[i+1][j+1] = dp[i][j]+1;
//                }else {
//                    dp[i+1][j+1] = max(dp[i+1][j], max(dp[i][j+1],dp[i][j]));
//                }
//                ans = max(ans, dp[i+1][j+1]);
//            }
//        return ans;
//    }
//};