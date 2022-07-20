/*
 *@File Name          :leetcode-14.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/20 10:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      int k = 0;
      while (k < ans.size() && k < strs[i].size() && ans[k] == strs[i][k]) k++;
      ans = ans.substr(0, k);
      if (ans.empty()) break;
    }
    return ans;
  }
};