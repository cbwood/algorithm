/*
 * @File Name          :leetcode-1036.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/11 15:03
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "queue"
#include "unordered_map"

using namespace std;

typedef long long LL;
const LL upBound = 1e6;

class Solution {
public:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
        unordered_map<LL, bool> vis1;
        for (auto &x: blocked) {
            vis1[x[0] * upBound + x[1]] = true;
        }
        int n = blocked.size();
        n = n * (n - 1) / 2;
        if (n == 0) return true;
        int ans = dfs(n, vis1, source, target);
        if (ans == 1) return true;
        if (ans == -1) return false;
        ans = dfs(n, vis1, target, source);
        if (ans == -1) return false;
        return true;
    }

    int dfs(int n, unordered_map<LL, bool> &vis1, vector<int> &source, vector<int> &target) {
        unordered_map<LL, bool> vis;
        queue<pair<int, int>> que;
        que.push(make_pair(source[0], source[1]));
        vis[source[0] * upBound + source[1]] = true;
        while (!que.empty() && n > 0) {
            pair<int, int> pa = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int sx = pa.first + dx[i];
                int sy = pa.second + dy[i];
                if (sx == target[0] && sy == target[1]) return 1;
                if (sx >= 0 && sy >= 0 && sx < upBound && sy < upBound && !vis[sx * upBound + sy] &&
                    !vis1[sx * upBound + sy]) {
                    n--;
                    if (n == 0) return 0;
                    vis[sx * upBound + sy] = true;
                    que.push(make_pair(sx, sy));
                }
            }
        }
        if (n <= 0) return 0;
        return -1;
    }
};