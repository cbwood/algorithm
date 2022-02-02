/*
 * @File Name          :leecode-2045.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/24 10:32
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "iostream"
#include "vector"
#include "cstring"
#include "queue"
#include "algorithm"

using namespace std;

struct edge {
    int v, d;

    edge(int cv, int cd) : v(cv), d(cd) {}
};

class Solution {
public:
    static const int maxn = 1e4 + 10;
    int d[maxn], d2[maxn];
    vector<edge> e[maxn];

    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change) {

        for (auto &x: edges) {
            e[x[0]].emplace_back(time, x[1]);
            e[x[1]].emplace_back(time, x[0]);
        }
        dijkstra(1, n, change);
        return d2[n];
    }

    void dijkstra(int s, int n, int change) {
        memset(d, 0x7f, sizeof d);
        memset(d2, 0x7f, sizeof d2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> que;

        d[s] = 0;
        que.emplace(0, s);
        while (!que.empty()) {
            pair<int, int> p = que.top();
            que.pop();
            if (p.first > d2[p.second]) continue;
            if ((p.first / change) & 1) p.first = p.first + change - p.first % change;

            for (int i = 0; i < e[p.second].size(); i++) {
                int v = p.first + e[p.second][i].v;
                int dd = e[p.second][i].d;

                if (v < d[dd]) {
                    swap(d[dd], v);
                    que.emplace(d[dd], dd);
                }
                if (v > d[dd] && v < d2[dd]) {
                    d2[dd] = v;
                    que.emplace(v, dd);
                }
            }
        }
    }
};