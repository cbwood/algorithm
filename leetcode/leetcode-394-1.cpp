/*
 *@File Name          :leetcode-394-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/23 9:20
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "stack"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    stack<string> sta;
    for (auto& x : s) {
      if (x == ']') {
        string t;
        while (sta.top() != "[") {
          t = sta.top() + t;
          sta.pop();
        }
        sta.pop();
        int nums = 0;
        int d    = 1;
        while (!sta.empty() && isdigit(sta.top()[0])) {
          nums = nums + stoi(sta.top()) * d;
          d    = d * 10;
          sta.pop();
        }
        string tmp = t;
        while (nums > 1) {
          t += tmp;
          nums--;
        }
        sta.push(t);
      } else {
        sta.push(string(1, x));
      }
    }
    string ans;
    while (!sta.empty()) {
      ans = sta.top() + ans;
      sta.pop();
    }
    return ans;
  }
};