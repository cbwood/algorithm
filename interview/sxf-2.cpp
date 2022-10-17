#include <bits/stdc++.h>

using namespace std;

int main() {
  int       n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);

  for (int i = 0; i < n; i++) { cin >> a[i]; }
  int ans = 0;

  long long minx = a[0], maxx = a[0];
  int       r = 1;
  while (r < n) {
    minx = min(minx, a[r]);
    maxx = max(maxx, a[r]);
    if (maxx - minx > 2 * x) {
      minx = a[r];
      maxx = a[r];
      ans++;
    }
    r++;
  }
  ans++;
  cout << ans - 1 << endl;
  return 0;
}