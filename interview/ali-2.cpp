/*
 *@File Name          :ali-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/25 10:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> que;
    int n;
    cin >> n;
    int a[10];
    while (n--) {
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        que.push(a1);
        que.push(a2);
        que.push(a3);
        que.push(a4);
        que.push(a5);
        int top1 = que.top();
        int ans = 0;
        que.pop();
        ans += top1;
        int x = 3;
        while (x--) {
            a[x] = que.top() - top1;
            que.pop();
        }
        for (int i = 0; i < 3; i++) {
            if (a[i] > 0) {
                que.push(a[i]);
            }
        }
        if (que.size() >= 4) {
            top1 = que.top();
            que.pop();
            ans += top1;
            x = 3;
            while (x--) {
                a[x] = que.top() - top1;
                que.pop();
            }
            for (int i = 0; i < 3; i++) {
                if (a[i] > 0) {
                    que.push(a[i]);
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}