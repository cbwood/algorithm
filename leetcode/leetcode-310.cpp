/*
 *@File Name          :leetcode-310.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/6 16:03
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "queue"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    vector<vector<int>> e;
    vector<int> d, ans, p;
    int c;

    void dfs(int cur, int pre) {
        for (auto &x: e[cur]) {
            if (x != pre) {
                d[x] = d[cur] + 1;
                if (d[x] > d[c]) {
                    c = x;
                }
                p[x] = cur;
                dfs(x, cur);
            }
        }
    }

    vector<int> findMinHeightTrees1(int n, vector<vector<int>> &edges) {
        e = vector<vector<int>>(n, vector<int>());
        d = vector<int>(n, 0);
        p = vector<int>(n, -1);
        c = 0;
        for (auto &x: edges) {
            e[x[0]].emplace_back(x[1]);
            e[x[1]].emplace_back(x[0]);
        }
        dfs(0, -1);
        d[c] = 0;
        dfs(c, -1);
        int k = 0;
        int t = c;
        while (c != -1 && d[t] >= k) {
            if (k == d[t] / 2 || d[t] - k == d[t] / 2) ans.emplace_back(c);
            c = p[c];
            k++;
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        e = vector<vector<int>>(n, vector<int>());
        d = vector<int>(n, 0);
        for (auto &x: edges) {
            e[x[0]].emplace_back(x[1]);
            e[x[1]].emplace_back(x[0]);
            d[x[0]]++;
            d[x[1]]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
            if (d[i] == 1)
                que.emplace(i);
        int res = n;
        while (res > 2) {
            int m = que.size();
            res -= m;
            while (m--) {
                int k = que.front();
                que.pop();
                for (auto &x: e[k]) {
                    d[x]--;
                    if (d[x] == 0)
                        que.emplace(x);
                }
            }
        }
        while (!que.empty()) {
            ans.emplace_back(que.front());
            que.pop();
        }
        return ans;
    }
};