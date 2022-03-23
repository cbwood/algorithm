/*
 *@File Name          :baidu-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:03
 *@Description        : 对于每个像素，按照矩阵放大k倍
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;
int a[1001][1001];
int b[1001][1001];

void expe(int x, int y, int k, int t) {
    for (int i = x; i < x + k; i++) {
        for (int j = y; j < y + k; j++)
            b[i][j] = t;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            expe(i * k, j * k, k, a[i][j]);
        }
    }
    for (int i = 0; i < n * k; i++) {
        for (int j = 0; j < n * k - 1; j++) {
            cout << b[i][j] << " ";
        }
        cout << b[i][n * k - 1] << endl;

    }
    return 0;
}