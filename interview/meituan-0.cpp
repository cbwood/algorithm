/*
 *@File Name          :meituan-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 10:04
 *@Description        :垃圾双色球
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, r, b;
    cin >> n >> b >> r;
    string s;
    cin >> s;
    int numr = 0, numb = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == 'r') {
                numb++;
            } else numr++;
        }
    }
    if (numr <= r && numb <= b) {
        cout << numr + numb + n << endl;
    } else {
        cout << max(0, numb - b) << " " << max(0, numr - r) << endl;
    }
}