/*
 *@File Name          :netease-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 16:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> s;
queue<tuple<short, short, short, set<short>>> que;
bool vis[101][101];
int n, m, k;


void dfs(int sx, int sy, int st, int kk, set<short> &se) {
    if (kk == k) return;
    for (int i = 0; i < 4; i++) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && s[tx][ty] != 'W' && se.count(tx * 100 + ty) == 0) {
            se.insert(tx * 100 + ty);
            if (s[tx][ty] != 'M')
                que.push({tx, ty, st + 1, se});
            dfs(tx, ty, st, kk + 1, se);
            se.erase(tx * 100 + ty);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        s.clear();

        for (int i = 0; i < n; i++) {
            string ss;
            cin >> ss;
            s.emplace_back(ss);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'S') {
                    que.push({i, j, 0, {}});
                }
            }
        int ans = INT_MAX;
        while (!que.empty()) {
            auto x = que.front();
            que.pop();
            short sx = get<0>(x);
            short sy = get<1>(x);
            short st = get<2>(x);
            set<short> se = get<3>(x);
            if (s[sx][sy] == 'E') {
                ans = min(ans, st);
            } else
                dfs(sx, sy, st, 0, se);
        }
        if (ans == INT_MAX) ans = -1;
        cout << ans << endl;
    }
    return 0;
}