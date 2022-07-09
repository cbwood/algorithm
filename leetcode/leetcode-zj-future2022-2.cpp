/*
 *@File Name          :leetcode-zj-future2022-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/8 10:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& chess) {
    vector<int> sumx(chess.size() + 1, 0);

    for (int i = 1; i <= chess.size(); i++)
      sumx[i] = sumx[i - 1] + chess[i - 1];

    int ans = INT_MAX / 2;
    int k   = sumx[chess.size()];
    if (k == 0) return 0;
    for (int i = k; i <= chess.size(); i++) {
      ans = min(ans, k - sumx[i] + sumx[i - k]);
    }
    return ans;
  }
};