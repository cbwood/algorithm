/*
 *@File Name          :leetcode-718.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/18 9:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int                 n = nums1.size();
    int                 m = nums2.size();
    vector<vector<int>> dp(2, vector<int>(m + 1, 0));
    int                 ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i & 1][j] = 0;
        if (nums1[i - 1] == nums2[j - 1])
          dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + 1;

        //         dp[i][j] = max(dp[i-1][j], max(dp[i][j], dp[i][j-1]));
        ans = max(ans, dp[i & 1][j]);
      }
    }
    return ans;
  }
};