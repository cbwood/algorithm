/*
 *@File Name          :ali-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 19:12
 *@Description        :任意进制转10进制
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int up = 2;
    for (auto &x: s) {
        if (isalpha(x)) {
            up = max(up, x - 'A' + 10);
        } else up = max(up, x - '0');
    }
    vector<int> tans;
    for (int i = up; i <= 16; i++) {
        long long ans = 0;
        for (auto &x: s) {
            if (isalpha(x)) {
                ans = ans * i + x - 'A' + 10;
            } else ans = ans * i + x - '0';
            ans = ans % mod;
        }
        tans.emplace_back(ans);
    }
    std::sort(tans.begin(), tans.end());
    int pre = -1;
    for (auto &x: tans) {
        if (x != pre) {
            pre = x;
            cout << x << endl;
        }
    }
}