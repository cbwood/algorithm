/*
 *@File Name          :offer2-060.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/20 9:25
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "map"
#include "queue"

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> ma;
        for (auto &x: nums)
            ma[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;

        for (auto &x: ma) {
            if (que.size() == k) {
                if (que.top().first < x.second) {
                    que.pop();
                    que.emplace(x.second, x.first);
                }
            } else {
                que.emplace(x.second, x.first);
            }
        }
        vector<int> ans;
        while (!que.empty()) {
            auto x = que.top();
            que.pop();
            ans.emplace_back(x.second);
        }
        return ans;
    }
};