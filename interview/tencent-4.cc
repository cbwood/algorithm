/*
 *@File Name          :tencent-4.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 21:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int main() {
    int n, m;;
    cin >> n >> m;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> dp1(n + 5, 0);//现金-买
    vector<int> dp2(n + 5, 0);//股票手
    vector<int> dp11(n + 5, 0);//现金
    vector<int> dp22(n + 5, 0);//股票手
    dp1[0] = m;
    dp11[0] = m;
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 0; j--) {
            if (dp1[i] + dp2[i] * a[i] <= dp1[j] + dp2[j] * a[j]) {
                dp1[i] = dp1[j];
                dp2[i] = dp2[j];
            }
            if (dp11[i] + dp22[i] * a[i] <= dp11[j] + dp22[j] * a[j]) {
                dp11[i] = dp11[j];
                dp22[i] = dp22[j];
            }
            if (dp1[i] + dp2[i] * a[i] < dp1[j] / a[i] * a[i] + dp2[j] * a[i]) {
                dp1[i] = dp1[j] - dp1[j] / a[i] * a[i];
                dp2[i] = dp1[j] / a[i] + dp2[j];
            }
            if (dp1[i] + dp2[i] * a[i] < dp11[j] / a[i] * a[i] + dp22[j] * a[i]) {
                dp1[i] = dp11[j] - dp11[j] / a[i] * a[i];
                dp2[i] = dp11[j] / a[i] + dp22[j];
            }

            if (dp11[i] + dp22[i] * a[i] <= dp1[j] + dp2[j] * (a[i] - a[j])) {
                dp11[i] = dp1[j] + dp2[j] * (a[i] - a[j]);
                dp22[i] = 0;
            }
            if (dp11[i] + dp22[i] * a[i] <= dp11[j] + dp22[j] * (a[i] - a[j])) {
                dp11[i] = dp11[j] + dp22[j] * (a[i] - a[j]);
                dp22[i] = 0;
            }
        }
    cout << max(dp1[n] + dp2[n] * a[n], dp11[n] + dp22[n] * a[n]) << endl;
    return 0;
}