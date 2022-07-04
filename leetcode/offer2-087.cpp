/*
 *@File Name          :offer2-087.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/4 10:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<string> ans;

  void dfs(string s, int k, vector<int>& q, int i) {
    if (k == 3) {
      if ((s[i] == '0' && i < s.size() - 1) || (int)s.size() - i > 3) return;
      int tmp = stoi(s.substr(i));
      if (tmp <= 255) {
        string t;
        for (auto& x : q) {
          t.append(to_string(x));
          t.push_back('.');
        }
        t.append(to_string(tmp));
        ans.push_back(t);
      }
      return;
    }
    int nums = 0;
    for (int j = i; j < (int)s.size() - 1; j++) {
      nums = nums * 10 + s[j] - '0';
      if (nums > 255) break;
      q.push_back(nums);
      dfs(s, k + 1, q, j + 1);
      q.pop_back();
      if (s[i] == '0') break;
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<int> tmp;
    dfs(s, 0, tmp, 0);
    return ans;
  }
};