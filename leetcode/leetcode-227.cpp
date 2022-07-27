/*
 *@File Name          :leetcode-227.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/27 10:27
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "stack"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  int cal(char opt, int x, int y) {
    if (opt == '*') return x * y;
    if (opt == '-') return x - y;
    if (opt == '/') return x / y;
    if (opt == '+') return x + y;
    return 0;
  }
  bool check(const char a, const char b) {
    if (a == '*' || a == '/') return true;
    return false;
  }
  int calculate(string s) {
    stack<int>  nums;
    stack<char> opt;
    int         k    = 0;
    int         flag = 1;
    for (auto& x : s) {
      if (x == ' ') continue;
      if (isdigit(x)) {
        k = k * 10 + (x - '0');
      } else {
        nums.push(k * flag);
        if (x == '-') {
          x    = '+';
          flag = -1;
        } else
          flag = 1;
        k = 0;
        if (opt.empty())
          opt.push(x);
        else {
          if (check(opt.top(), x)) {
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            a = cal(opt.top(), a, b);
            opt.pop();
            nums.push(a);
          }
          opt.push(x);
        }
      }
    }
    nums.push(k * flag);
    while (!opt.empty()) {
      int b = nums.top();
      nums.pop();
      int a = nums.top();
      nums.pop();
      a = cal(opt.top(), a, b);
      opt.pop();
      nums.push(a);
    }
    k = nums.top();
    return k;
  }
};