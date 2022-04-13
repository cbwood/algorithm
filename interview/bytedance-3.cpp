/*
 *@File Name          :bytedance-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/10 10:41
 *@Description        :超市买东西集邮
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int ans = INT_MAX;
vector<string> a;
vector<set<char>> ase;

void dfs(set<char> se, int cur, int n, int sumx) {
    if (se.size() == 10 && sumx < ans) {
        ans = sumx;
        return;
    }
    if (cur == n) {
        return;
    }

    if (sumx >= ans) return;
    set<char> tt;
    set_union(se.begin(), se.end(), ase[cur].begin(), ase[cur].end(), inserter(tt, tt.begin()));
    if (tt.size() != 10) {
        return;
    }
    set<char> tse = se;
    tse.insert(a[cur][0]);
    tse.insert(a[cur][1]);
    tse.insert(a[cur][2]);
    dfs(tse, cur + 1, n, sumx + 1);
    dfs(se, cur + 1, n, sumx);

}

int main() {
    string s;
    getline(cin, s);
    set<char> tse;
    for (int i = 0; i < s.size(); i += 4) {
        a.push_back(s.substr(i, 3));
        tse.insert(s[i]);
        tse.insert(s[i + 1]);
        tse.insert(s[i + 2]);
        if (tse.size() == 10) {
            ans = min(ans, (int) tse.size());
        }
    }
    if (tse.size() != 10) {
        cout << -1 << endl;
        return 0;
    }
    tse.clear();
    int n = a.size();
    ase = vector<set<char>>(n, set<char>());
    ase[n - 1].insert(a[n - 1][0]);
    ase[n - 1].insert(a[n - 1][1]);
    ase[n - 1].insert(a[n - 1][2]);
    for (int i = n - 2; i >= 0; --i) {
        ase[i] = ase[i + 1];
        ase[i].insert(a[i][0]);
        ase[i].insert(a[i][1]);
        ase[i].insert(a[i][2]);
    }

    dfs(tse, 0, n, 0);
    cout << ans << endl;
    return 0;
}