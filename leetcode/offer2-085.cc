/*
 *@File Name          :offer2-085.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/1 9:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; j++) {
        for (auto& x : dp[j]) {
          for (auto& y : dp[i - j - 1]) dp[i].emplace_back("(" + x + ")" + y);
        }
      }
    }
    return dp[n];
  }
};