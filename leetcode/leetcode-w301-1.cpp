/*
 *@File Name          :leetcode-w301-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/10 11:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int fillCups(vector<int>& amount) {
    priority_queue<int, vector<int>, less<>> que;
    if (amount[0]) que.push(amount[0]);
    if (amount[1]) que.push(amount[1]);
    if (amount[2]) que.push(amount[2]);

    int ans = 0;
    while (!que.empty()) {
      int t1 = que.top();
      que.pop();
      if (que.empty()) {
        ans += t1;
        break;
      }
      int t2 = que.top();
      que.pop();
      t1--;
      t2--;
      ans++;
      if (t1) que.push(t1);
      if (t2) que.push(t2);
    }
    return ans;
  }
};