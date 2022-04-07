/*
 *@File Name          :jd-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 19:23
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
        string s;
        cin >> n >> s;
        int ans = 0;
        vector<pair<int, char>> a;
        a.emplace_back(0, 'A');
        a.emplace_back(0, 'B');
        a.emplace_back(0, 'C');
        for (auto &x: s) {
            a[x - 'A'].first++;
        }
        std::sort(a.begin(), a.end());
        if (a[0].first == a[1].first && a[1].first == a[2].first) {
            cout << ans << endl;
            continue;
        }
        if (a[1].first > n) {
            int b[3] = {0, a[1].first - n, a[2].first - n};
            int l = 0, r = 0;
            while (r < 3 * n) {
                b[s[r] - 'A']--;
                while (b)
            }
        }


    }
    return 0;
}