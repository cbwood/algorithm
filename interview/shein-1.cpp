/*
 *@File Name          :shein-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/7 15:09
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "map"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int ans = 0;

  vector<int> dp;

  int dfs(int cur, string& s) {
    if (cur > s.size()) return 0;
    if (dp[cur] != -1) return dp[cur];
    if (cur == s.size()) return 1;

    if (s[cur] == '0') { return 0; }
    if (s[cur] == '1') { return dp[cur] = dfs(cur + 1, s) + dfs(cur + 2, s); }
    if (s[cur] == '2') {
      dp[cur] = dfs(cur + 1, s);
      if (cur < s.size() - 1 && s[cur + 1] <= '6') dp[cur] += dfs(cur + 2, s);
      return dp[cur];
    }
    dp[cur] = dfs(cur + 1, s);
    return dp[cur];
  }
  /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
  int numDecoding(string s) {
    // write code here
    dp.resize(s.size() + 1, -1);
    return dfs(0, s);
  }
};