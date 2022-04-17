/*
 *@File Name          :netease-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 15:16
 *@Description        :
 *@Function List      :
 *@History            :
 */


#include "bits/stdc++.h"

using namespace std;
int n;
vector<vector<pair<int, int>>> a;
int ans;
vector<int> maxe(7, 0);
vector<int> pre;

bool dfs(int cur, int sum1, int sum2) {
    if (cur == 7) {
        if (sum1 >= 100) {
            ans = max(ans, sum2);
            return true;
        }
        return false;
    }
    if (sum1 >= 100) {
        return dfs(cur + 1, sum1, sum2 + maxe[cur]);
    }
    if (sum2 + pre[cur] <= ans) {
        return true;
    }
    bool flag = false;
    for (auto &x: a[cur]) {
        if (!dfs(cur + 1, sum1 + x.first, sum2 + x.second))
            break;
        else flag = true;
    }
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = -1;
        a = vector<vector<pair<int, int>>>(7);
        maxe = vector<int>(7, 0);
        pre = vector<int>(8, 0);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x].push_back({y, z});
            maxe[x] = max(maxe[x], z);
        }
        for (int i = 1; i < 7; i++) {
            std::sort(a[i].begin(), a[i].end(), greater<>());
        }
        for (int i = 6; i >= 0; i--)
            pre[i] = pre[i + 1] + maxe[i];

        dfs(1, 0, 0);
        if (ans == -1)
            cout << "TAT" << endl;
        else cout << ans << endl;
    }
    return 0;
}
/*
 *
2
12
1 12 6
1 14 10
2 22 3
2 3 38
3 24 1
3 3 15
3 11 23
4 13 2
5 19 10
5 17 11
5 16 2
6 20 2
11
1 14 16
1 17 3
2 6 32
3 3 24
4 12 3
4 13 0
5 22 5
5 21 4
6 3 37
6 14 6
6 23 0
 */


