/*
 *@File Name          :360-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 15:51
 *@Description        :算能组成几个4人队伍
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = d + min(a, c) + b / 2;
        if (a > c) {
            if (b & 1 && a - c >= 2) ans++;
            ans += (a - c - 2) / 4;
        }
        int ans2 = d + min(a, c);
        if (a > c) {
            a -= c;
            ans2 += min(b, a / 2);
            if (b < a / 2) {
                a -= b * 2;
                ans2 += a / 4;
            } else {
                ans2 += (b - a / 2) / 2;
            }
        }
        cout << max(ans, ans2) << endl;

    }
    return 0;
}