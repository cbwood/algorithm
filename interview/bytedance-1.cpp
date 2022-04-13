/*
 *@File Name          :bytedance-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/10 10:19
 *@Description        :吃能量棒走路
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sumx = 0;
    for (int i = 0; i < n; i++) {
        sumx = max(sumx - 1, a[i]);
        if (sumx <= 0 && i != n - 1) {
            cout << "FALSE" << endl;
            return 0;
        }
    }
    cout << "TRUE" << endl;
    return 0;
}