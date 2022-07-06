/*
 *@File Name          :offer2-093.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 15:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "vector"
using namespace std;

class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n   = arr.size();
    int ans = 0;

    map<int, int>       ma;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
      ma[arr[i]] = i;
      for (int j = 0; j < i; j++) {
        int k = arr[i] - arr[j];
        if (ma.count(k) && ma[k] < j)
          dp[i][j] = dp[j][ma[k]] + 1;
        else
          dp[i][j] = 2;
        ans = max(ans, dp[i][j]);
      }
    }
    return ans > 2 ? ans : 0;
  }
};