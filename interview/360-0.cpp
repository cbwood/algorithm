/*
 *@File Name          :360-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 15:40
 *@Description        :给分数求及格人数
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    int p, q;
    cin >> n >> p >> q;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int pScore = 100;
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] * q + pScore * p >= 6000)
            ans++;
        else
            break;
        if (i > 0 && v[i] > v[i - 1])
            pScore--;
    }
    cout << ans << endl;
}