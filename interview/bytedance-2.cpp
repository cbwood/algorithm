/*
 *@File Name          :bytedance-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/10 10:23
 *@Description        :多个双端队列判定
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
        int m = 0;
        vector<deque<int>> dq(n, deque<int>());
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x--) {
                int y;
                cin >> y;
                m++;
                dq[i].emplace_back(y);
            }
        }
        while (m) {
            bool check = false;
            for (int i = 0; i < n; i++) {
                if (!dq[i].empty()) {
                    if (dq[i].front() == m) {
                        m--;
                        check = true;
                        dq[i].pop_front();
                    } else if (dq[i].back() == m) {
                        m--;
                        check = true;
                        dq[i].pop_back();
                    }
                }
                if (check)
                    break;

            }
            if (!check)
                break;
        }
        if (m > 0)
            m = 0;
        else m = 1;
        cout << m << endl;
    }
    return 0;
}