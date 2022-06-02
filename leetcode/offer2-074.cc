/*
 *@File Name          :offer2-074.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/2 8:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int>& p, const vector<int>& q) -> bool {
                if (p[0] == q[0]) return p[1] < q[1];
                return p[0] < q[0];
              });
    vector<vector<int>> ans;
    ans.emplace_back(intervals[0]);
    int n = intervals.size();
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] <= ans.back()[1]) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      } else {
        ans.emplace_back(intervals[i]);
      }
    }
    return ans;
  }
};