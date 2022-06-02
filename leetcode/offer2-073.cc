/*
 *@File Name          :offer2-073.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/2 8:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int  ans;
    int  l = 1, r = 1e9;
    auto check = [&piles, &h](int x) -> bool {
      int cnt = 0;
      for (auto& pile : piles) { cnt += (pile + x - 1) / x; }
      return cnt <= h;
    };
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (check(mid)) {
        ans = mid;
        r   = mid - 1;
      } else
        l = mid + 1;
    }
    return ans;
  }
};