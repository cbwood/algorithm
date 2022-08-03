/*
 *@File Name          :leetcode-402.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/3 10:09
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "stack"
#include "string"
using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> sta;
    for (auto& x : num) {
      if (k <= 0 || sta.empty() || sta.top() <= x) {
        sta.push(x);
      } else {
        while (k > 0 && !sta.empty() && sta.top() > x) {
          sta.pop();
          k--;
        }
        sta.push(x);
      }
    }
    while (k > 0 && !sta.empty()) {
      sta.pop();
      k--;
    }
    string ans;
    while (!sta.empty()) {
      ans += sta.top();
      sta.pop();
    }
    while (!ans.empty() && ans.back() == '0') ans.pop_back();
    if (ans.empty()) ans = "0";
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};