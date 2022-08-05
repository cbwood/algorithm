/*
 *@File Name          :leetcode-139.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/5 9:40
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "set"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int          n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    set<string> w;
    set<int>    len;
    for (auto& x : wordDict) {
      w.insert(x);
      len.insert(x.size());
    }
    for (int i = 1; i <= n; i++) {
      for (auto& x : len) {
        if (x > i) break;
        if (dp[i - x] && w.find(s.substr(x, i - x)) != w.end()) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[n];
  }
};