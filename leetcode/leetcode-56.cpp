/*
 *@File Name          :leetcode-56.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/5 9:00
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int pre = -1;
        int st;
        for (auto &x: intervals) {
            if (x[0] > pre) {
                if (pre != -1)
                    ans.push_back({st, pre});
                st = x[0];
                pre = x[1];
            } else {
                pre = max(pre, x[1]);
            }
        }
        ans.push_back({st, pre});
        return ans;
    }
};