/*
 *@File Name          :cmb-0.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/28 19:58
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma[a[i]] = 1;
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;
    int x = 0;
    for (int i = 0; i < n; i++) {
        while (ma[a[x]] == 0) {
            x++;
        }
        if (b[i] != a[x]) {
            ans++;
        } else {
            x++;
        }
        ma[b[i]] = 0;
    }
    cout << ans << endl;
    return 0;
}