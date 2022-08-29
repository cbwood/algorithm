/*
*@File Name          :bytedance-11.cpp
*@Author             :cc
*@Version            :1.0.0
*@Date               :2022/8/28 10:01
*@Description        :
*@Function List      :
*@History            :
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) { cin >> a[i]; }

    long long ans  = LONG_LONG_MIN;
    long long maxi = a[0];
    long long mini = a[0];
    int       l = 0, r = 0;
    int       tl   = 0;
    int       ansl = 0, ansr = 0;

    vector<long long> maxdp(n), mindp(n);
    maxdp[0] = a[0];
    mindp[0] = a[0];
    int ansi = 0;

    for (int i = 1; i < n; i++) {
      auto x   = a[i];
      maxdp[i] = max(maxdp[i - 1] * x, max(mindp[i - 1] * x, x * 1LL));
      mindp[i] = min(mindp[i - 1] * x, min(maxdp[i - 1] * x, 1LL * x));

      if (maxdp[i] > maxdp[ansi]) { ansi = i; }
    }

    ansr = ansi;

    long long tmp = 1;
    while (ansi >= 0) {
      tmp = tmp * a[ansi];
      if (tmp == maxdp[ansr]) ansl = ansi;
      ansi--;
    }
    cout << ansl + 1 << " " << ansr + 1 << endl;
  }

  return 0;
}