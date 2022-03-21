/*
 *@File Name          :leetcode-2039.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/20 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
        int n = patience.size();
        vector<int> e[n];
        for (auto &x: edges) {
            e[x[0]].emplace_back(x[1]);
            e[x[1]].emplace_back(x[0]);
        }
        vector<int> dist(n, INT_MAX);
        auto dijkstra = [&]() -> void {
            dist[0] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int> >, greater<>> que;
            que.emplace(0, 0);
            while (!que.empty()) {
                pair<int, int> p = que.top();
                que.pop();
                if (dist[p.second] < p.first) continue;
                for (auto &x: e[p.second]) {
                    if (dist[x] > dist[p.second] + 1) {
                        dist[x] = dist[p.second] + 1;
                        que.emplace(dist[x], x);
                    }
                }
            }
        };
        auto dijkstra1 = [&]() -> void {
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (auto &next: e[t]) {
                    if (!dist[next]) {
                        q.push(next), dist[next] = dist[t] + 1;
                    }
                }
            }
        };
        dijkstra();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            int v = dist[i] * 2;
            int k = ((v - 1) / patience[i]) * patience[i] + v;
            ans = max(ans, k);
        }
        return ans + 1;
    }
};