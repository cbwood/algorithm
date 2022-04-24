/*
 *@File Name          :bytedance-4.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 13:04
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int n, m;
vector<vector<int>> a;


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int sx, int sy) {
    int ans = 1;
    a[sx][sy] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        if (tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty] == 0) {
            ans += dfs(tx, ty);
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    a == vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                ans = max(ans, dfs(i, j));
            }
        }
    cout << ans << endl;
    return 0;

}