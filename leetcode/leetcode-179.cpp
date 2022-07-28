/*
 *@File Name          :leetcode-179.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/28 9:28
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
  string largestNumber(vector<int>& nums) {
    vector<string> a;
    for (auto& x : nums) { a.emplace_back(to_string(x)); }
    std::sort(a.begin(), a.end(),
              [](const string& p, const string& q) { return p + q > q + p; });

    string ans;
    for (const auto& x : a) ans += x;
    if (ans.empty()) ans = "0";
    std::reverse(ans.begin(), ans.end());

    while (ans.size() > 1 && ans[ans.size() - 1] == '0') ans.pop_back();
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};