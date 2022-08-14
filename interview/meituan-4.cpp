/*
 *@File Name          :meituan-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/6 10:18
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<set<int>> dp(k + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    dp[x].insert(i);
  }
  vector<int> ans1, ans2;
  for (int i = 1; i <= k; i++) {
    int n = dp[i].size();
    int k = (n + 1) / 2;
    for (auto& x : dp[i]) {
      if (k > 0) {
        ans1.push_back(x);
      } else
        ans2.push_back(x);
      k--;
    }
  }
  n = ans1.size();
  std::sort(ans1.begin(), ans1.end());
  std::sort(ans2.begin(), ans2.end());
  for (int i = 0; i < n - 1; i++) { cout << ans1[i] << " "; }
  cout << ans1[n - 1] << endl;
  n = ans2.size();

  for (int i = 0; i < n - 1; i++) { cout << ans2[i] << " "; }
  cout << ans2[n - 1] << endl;
  return 0;
}