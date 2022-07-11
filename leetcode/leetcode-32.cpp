/*
 *@File Name          :leetcode-32.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/11 9:43
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "queue"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int         n = s.size();
    vector<int> dp(n, 0);
    int         ans = 0;

    priority_queue<int> que;
    for (int i = 1; i < n; i++) {
      if (s[i] == ')' && i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
        dp[i] += dp[i - 1] + 2;
      if (i - 1 - dp[i - 1] - 1 >= 0 && dp[i])
        dp[i] += dp[i - 1 - dp[i - 1] - 1];
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};