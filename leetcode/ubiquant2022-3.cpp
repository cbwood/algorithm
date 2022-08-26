/*
 *@File Name          :ubiquant2022-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 17:40
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int minOperations(vector<int>& numbers) {
    long long t = numbers[0];
    int       n = numbers.size();
    for (int i = 0; i < n; i++) {
      int k = gcd(t, numbers[i]);
      t     = t * numbers[i] / k;
    }
    int ans = 0;
    for (auto& x : numbers) {
      if (t % x != 0) return -1;
      long long tmp = t / x;
      while (tmp > 1 && tmp % 2 == 0) {
        ans++;
        tmp /= 2;
      }

      while (tmp > 1 && tmp % 3 == 0) {
        ans++;
        tmp /= 3;
      }
      if (tmp != 1) return -1;
    }
    return ans;
  }
};