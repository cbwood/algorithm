/*
 *@File Name          :offer2-092.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 15:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int minFlipsMonoIncr(string s) {
    int n = s.size();

    vector<int> num0(n, 0);
    vector<int> num1(n, 0);

    if (s[0] == '0')
      num0[0]++;
    else
      num1[0]++;
    for (int i = 1; i < n; i++) {
      if (s[i] == '0')
        num0[i]++;
      else
        num1[i]++;

      num0[i] += num0[i - 1];
      num1[i] += num1[i - 1];
    }

    int ans = min(num1[n - 1], num0[n - 1]);

    for (int i = 0; i < n - 1; i++) {
      ans = min(ans, num1[i] + num0[n - 1] - num0[i]);
    }
    return ans;
  }
};