/*
 *@File Name          :baidu-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:04
 *@Description        :给长度为n只包含0或1的字符串，每次只能删除相邻两个字符中较小的，问字串有多少中，mod=1e9+7
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

const int mod = 1e9 + 7;

long long qpow(long long x, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    char pre = s[0];
    long long ans = 1;
    long long t = 0;
    int num = n;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (s[i] == s[i - 1])) {
            if (s[i] == '0')
                num--;
            t++;
        } else {
            if (s[i] == '1') {
                ans = ans * qpow(2, t) % mod;
                t = 1;
            } else {
                tmp++;
                ans = ans * ((qpow(2, t) - 1 + mod) % mod) % mod;
                t = 1;
            }

        }
    }
    if (t > 0) {
        if (s[n - 1] == '0')
            ans = ans * 2 % mod;
        else {
            ans = ans * ((qpow(2, t) - 1 + mod) % mod) % mod;
            tmp++;
        }
    }
    long long ttt = tmp * (tmp - 1) / 2;
    cout << (ans + mod) % mod + (ttt % mod) % mod << endl;
    return 0;
}
