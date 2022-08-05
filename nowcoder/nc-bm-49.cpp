/*
 *@File Name          :nc-bm-49.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/4 10:33
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
  /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */

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
  int solve(string s) {
    // write code here
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
          long long a = nums.top();
          nums.pop();
          long long b = nums.top();
          nums.pop();
          nums.push(cal(op.top(), b, a));
          op.pop();
        }
        op.pop();
      } else {
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