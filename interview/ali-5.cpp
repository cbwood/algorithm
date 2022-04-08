/*
 *@File Name          :ali-5.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 19:47
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int sum[100004];

int main() {
    int k, n;
    string s;
    cin >> n >> k >> s;
    long long ans = 0;
    sum[0] = 1;
    set<char> se;
    se.insert(s[0]);
    for (int i = 1; i < n; i++) {
        se.insert(s[i]);
        sum[i] = se.size();
        if (sum[i] >= k) {
            ans += (n - i) * (n - i + n) / 2;
            break;
        }
    }
    se.clear();
    se.insert(s[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        se.insert(s[i]);
        sum[i] = se.size();
        if (sum[i] >= k) {
            ans += i * (i - 1) / 2;
            break;
        }
    }
    cout << ans << endl;


}