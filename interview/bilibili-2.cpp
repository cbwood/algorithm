#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> sum(n + 2, 0);
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) { sum[i + 1] = sum[i] + a[i]; }
  int q;
  cin >> q;
  long long sumx = 0;
  while (q--) {
    int x;
    cin >> x;
    sumx += x;
    int idx = lower_bound(a.begin(), a.end(), -sumx) - a.begin();
    cout << -sum[idx] + sum[n] - sum[idx] - sumx * idx + sumx * (n - idx)
         << endl;
  }
  return 0;
}