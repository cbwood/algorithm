/*
 *@File Name          :leetcode-2141.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/27 15:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long l = 0, r = 1e14;
    long long ans;
    while (l <= r) {
      long long mid  = l + (r - l) / 2;
      long long sumx = 0;
      for (auto& x : batteries) sumx += min(x * 1LL, mid);
      if (sumx >= n * mid) {
        l   = mid + 1;
        ans = mid;
      } else
        r = mid - 1;
    }
    return ans;
  }
};