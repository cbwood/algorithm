/*
 *@File Name          :leetcode-43.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/9 9:32
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1[0] == '0') return "0";
    if (num2[0] == '0') return "0";

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int n = num1.size();
    int m = num2.size();

    vector<int> a(n * m + 10, 0);

    for (int i = 0; i < n; i++) {
      int x = 0;
      int t = (num1[i] - '0');
      for (int j = 0; j < m; j++) {
        int k = t * (num2[j] - '0') + x;
        a[i + j] += k;
        x        = a[i + j] / 10;
        a[i + j] = a[i + j] % 10;
      }
      int k = m;
      while (x) {
        a[i + k] += x;
        x = a[i + k] / 10;
        a[i + k] %= 10;
        k++;
      }
    }
    string ans;
    int    k = n * m + 9;
    while (a[k] == 0) k--;
    while (k >= 0) {
      ans.push_back(a[k] + '0');
      k--;
    }
    return ans;
  }
};