/*
 *@File Name          :cmb-2.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/28 21:14
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;
vector<pair<int, int>> a;
int n;
long long ex, ey;
map<pair<long long, long long>, long long> ma;
long long ans[100];


long long dfs(long long x, long long y, int st, int num) {
    long long flag = 0;
//    if(ma.find({x,y}) != ma.end())
//        return ma.find({x,y})->second;
    if (x == ex && y == ey) {
        ans[num]++;
        flag = 1;
    }
    if (st == n) return flag;
    flag += dfs(x + a[st].first, y + a[st].second, st + 1, num + 1);
    flag += dfs(x, y, st + 1, num);
    ma[{x, y}] = flag;
    return flag;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    dfs(0, 0, 0, 0);
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}