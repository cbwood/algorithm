/*
 *@File Name          :bytedance-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/10 9:57
 *@Description        :陆地被淹没
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int a[1000][1000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                a[i][j] = s[j] - '0';
            }
        }


        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    int num = 0;
                    for (int k = 0; k < 4; k++) {
                        int sx = i + dx[k];
                        int sy = j + dy[k];
                        if (sx >= 0 && sy >= 0 && sx < n && sy < m && a[sx][sy] == 0) {
                            num++;
                        }
                    }
                    if (num > 1) {
                        a[i][j] = -1;
                    }
                }
            }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == -1)
                    a[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                cout << a[i][j];
            }
            cout << a[i][m - 1] << endl;
        }
    }

    return 0;
}