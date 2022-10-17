#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int>& idx, int cur, int sumx, vector<int>& dp, vector<int>& a) {
  if (dp[cur] == -1) return;

  idx.push_back(dp[cur]);
  dfs(idx, cur - a[dp[cur]], sumx, dp, a);
}

int main() {
  int n;
  cin >> n;
  int         sumx = 0;
  vector<int> a(n);
  vector<int> idx;
  string      anss;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sumx += a[i];
    anss.push_back('Y');
  }
  vector<int> dp(sumx / 2 + 1, -1);

  for (int i = 0; i < n; i++) {
    for (int j = sumx / 2; j >= a[i]; j--)
      if (j - a[i] == 0 && dp[j] == -1) { dp[j] = i; }
  }

  int ansx = 0, ansy = 0;
  for (int i = sumx / 2; i > 0; --i) {
    if (dp[i] != -1) {
      dfs(idx, dp[i], sumx, dp, a);
      for (auto& t : idx) { anss[t] = 'X'; }
      ansx = i;
      ansy = i - sumx;
      break;
    }
  }

  if (ansx == 0) {
    cout << -1 << endl;
  } else {
    cout << ansx << " " << ansy << endl;
    cout << anss << endl;
  }
  return 0;
}