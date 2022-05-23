/*
 *@File Name          :offer2-061.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/23 8:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "queue"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<vector<int>> ans;
        int len1 = nums1.size();
        int len2 = nums2.size();

        auto cmp = [&nums1, &nums2](const pair<int, int> &p, const pair<int, int> &q) {
            return nums1[p.first] + nums2[p.second] > nums1[q.first] + nums2[q.second];
        };

        priority_queue<pair<int, int>, deque<pair<int, int>>, decltype(cmp)> que(cmp);
        for (int i = 0; i < min(k, len1); ++i) {
            que.emplace(i, 0);
        }

        while (k-- && !que.empty()) {
            auto node = que.top();
            que.pop();
            ans.emplace_back(initializer_list<int>{nums1[node.first], nums2[node.second]});
            if (node.second + 1 < len2) {
                que.emplace(node.first, node.second + 1);
            }
        }
        return ans;
    }
};