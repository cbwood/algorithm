/*
 *@File Name          :ksyun-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/6 20:22
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n != 1) {
            if (n & 1) n--;
            else n >>= 1;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}