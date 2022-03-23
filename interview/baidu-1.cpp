/*
 *@File Name          :baidu-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:03
 *@Description        :给长度为n只包含0或1的字符串，求两个可以相交但不能完全相同的区间使得0与1个数相同，求最大的区间
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int l[2] = {n, n};
    int r[2] = {-1, -1};
    for (int i = 0; i < n; i++) {
        l[s[i] - '0'] = min(l[s[i] - '0'], i);
        if (l[0] != n && l[1] != n)
            break;
    }
    for (int i = n - 1; i >= 0; i--) {
        r[s[i] - '0'] = max(r[s[i] - '0'], i);
        if (r[0] != -1 && r[1] != -1)
            break;
    }
    if (r[0] - l[0] > r[1] - l[1]) {
        cout << l[0] + 1 << " " << r[0] - 1 + 1 << " " << l[0] + 1 + 1 << " " << r[0] + 1;
    } else {
        cout << l[1] + 1 << " " << r[1] - 1 + 1 << " " << l[1] + 1 + 1 << " " << r[1] + 1;
    }
}