/*
 *@File Name          :leetcode-224.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/4 10:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "stack"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  long long cal(char opt, long long a, long long b) {
    switch (opt) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    return -1;
  }

  int calculate(string s) {
    map<char, int> prior;
    prior['+'] = 1;
    prior['-'] = 1;
    prior['*'] = 2;
    prior['/'] = 2;
    stack<char>      op;
    stack<long long> nums;
    nums.push(0);
    long long k = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      if (s[i] == '(') {
        op.push(s[i]);
      } else if (isdigit(s[i])) {
        int j = i;
        k     = 0;
        while (j < s.size() && isdigit(s[j])) { k = k * 10 + s[j++] - '0'; }
        nums.push(k);
        i = j - 1;
      } else if (s[i] == ')') {
        while (op.top() != '(') {
          int a = nums.top();
          nums.pop();
          int b = nums.top();
          nums.pop();
          nums.push(cal(op.top(), b, a));
          op.pop();
        }
        op.pop();
      } else {
        if (i > 0 && s[i - 1] == '(') nums.push(0);
        while (!op.empty() && prior[s[i]] <= prior[op.top()]) {
          int a = nums.top();
          nums.pop();
          int b = nums.top();
          nums.pop();
          nums.push(cal(op.top(), b, a));
          op.pop();
        }
        op.push(s[i]);
        k = 0;
      }
    }
    while (!op.empty()) {
      int a = nums.top();
      nums.pop();
      int b = nums.top();
      nums.pop();
      nums.push(cal(op.top(), b, a));
      op.pop();
    }
    return nums.top();
  }
};