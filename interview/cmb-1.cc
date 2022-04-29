/*
 *@File Name          :cmb-1.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/28 20:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;
const int maxn = 2010;
int a[maxn][maxn];
int b[maxn][maxn];

int ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[maxn][maxn];
map<pair<int, int>, int> ma;

void dfs(int x, int y) {
    a[x][y] = 1;
    if (b[x][y] == 4) return;
    if (vis[x][y]) return;
    if (x == 0 || x == 1001 || y == 0 || y == 1001)
        return;
    int num = 0;
    int k = 0;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (a[sx][sy] == 0)
            k = i;
        else num++;
    }
    if (num == 3) {
        int sx = x + dx[k];
        int sy = y + dy[k];
        ans++;
        ma[{sx, sy}] = 1;
        dfs(sx, sy);
    }
    num = 0;
    for (int i = 0; i < 4; i++) {
        int sx = x + dx[i];
        int sy = y + dy[i];
        if (a[sx][sy] == 1) {
            dfs(sx, sy);
            num++;
        }
    }
    b[x][y] = num;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        memset(vis, 0, sizeof vis);
        if (ma[{x + 100, y + 100}] == 1) {
            ans--;
            ma[{x + 100, y + 100}] = 0;
        }
        dfs(x + 100, y + 100);
        cout << ans << endl;
    }
    return 0;
}