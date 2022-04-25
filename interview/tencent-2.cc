/*
 *@File Name          :tencent-2.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 20:21
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> l0(n + 2, 0LL);
    vector<long long> r1(n + 2, 0LL);

    for (int i = 1; i <= n; i++) {
        l0[i] = l0[i - 1];
        if (s[i - 1] == '0')
            l0[i] += i;
    }
    for (int i = n; i >= 1; --i) {
        r1[i] = r1[i + 1];
        if (s[i - 1] == '1')
            r1[i] += i;
    }
    long long ans = LONG_LONG_MAX;
    for (int i = 0; i <= n; i++) {
//        cout<<l0[i]<<" "<<r1[i+1]<<endl;
        ans = min(ans, abs(l0[i] - r1[i + 1]));
    }
    cout << ans << endl;
    return 0;
}