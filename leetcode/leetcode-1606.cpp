/*
 *@File Name          :leetcode-1606.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/30 9:09
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "queue"
#include "set"

using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;
        set<int, less<>> se;
        for (int i = 0; i < k; i++)
            se.insert(i);
        int ans = 0;
        vector<int> nums(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            while (!que.empty() && que.top().first <= arrival[i]) {
                se.insert(que.top().second);
                que.pop();
            }
            if (!se.empty()) {
                auto t = se.lower_bound(i % k);
                if (t == se.end()) {
                    t = se.begin();
                }
                nums[*t]++;
                ans = max(ans, nums[*t]);
                que.push({arrival[i] + load[i], *t});
                se.erase(t);
            }
        }
        vector<int> tmp;
        for (int i = 0; i < k; i++)
            if (nums[i] == ans)
                tmp.emplace_back(i);
        return tmp;
    }
};