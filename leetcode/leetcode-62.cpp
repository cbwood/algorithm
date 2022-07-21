/*
 *@File Name          :leetcode-62.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/21 9:44
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int         a = m + n - 2;
    int         b = n - 1;
    vector<int> sb(b + 1, 0);
    int         k   = a - b;
    int         ans = 1;
    while (a > k) {
      ans *= a;
      a--;
      for (int i = b; i > 1; i--) {
        if (sb[i] == 0 && ans % i == 0) {
          ans /= i;
          sb[i] = 1;
        }
      }
    }
    return ans;
  }
};