/*
 *@File Name          :offer2-038.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/3 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> sta;
        for (int i = n - 1; i >= 0; --i) {
            while (!sta.empty() && temperatures[i] >= temperatures[sta.top()]) {
                sta.pop();
            }
            if (!sta.empty())
                ans[i] = sta.top() - i;
            sta.push(i);
        }
        return ans;
    }
};