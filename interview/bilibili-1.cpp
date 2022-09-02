#include <bits/stdc++.h>
using namespace std;

int main() {
  int         n;
  int         t;
  const int   maxn = 1e3 + 1;
  set<int>    se;
  vector<int> a;
  for (int i = 2; i < maxn; i++) {
    bool check = true;
    for (int j = 2; j * j <= i && check; j++) {
      if (i % j == 0) { check = false; }
    }
    if (check) a.push_back(i);
  }

  for (int i = 0; i < a.size() && a[i] * a[i] < maxn * maxn; i++) {
    for (int j = 0;
         j < a.size() && 1LL * a[j] * a[j] * a[j] < 1LL * maxn * maxn; j++) {
      for (int k = 0;
           k < a.size() && 1LL * a[k] * a[k] * a[k] * a[k] < 1LL * maxn * maxn;
           k++) {
        se.insert(a[i] * a[i] + a[j] * a[j] * a[j] + a[k] * a[k] * a[k] * a[k]);
      }
    }
  }

  vector<int> ans(maxn * maxn + 100, 0);
  for (int i = 1; i < maxn * maxn + 10; i++) {
    ans[i] += ans[i - 1];
    if (se.count(i)) ans[i]++;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    cout << ans[n] << endl;
  }
  return 0;
}