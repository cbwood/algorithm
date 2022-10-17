#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long maxn = 0;
  long long num1 = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0') {
      num1 = 0;
    } else
      num1++;
    maxn = max(maxn, num1);
  }

  long long mod = 1e9 + 7;

  long long ans = 0;


  long long l = 0, r = 0;
  num1 = 0;
  while (r < n && maxn) {
    if (s[r] == '1')
      num1++;
    else {
      num1 = 0;
      l    = r + 1;
    }
    if (num1 == maxn) {
      ans = ans + (l + 1) * (n - r);
      ans = ans % mod;
    }
    r++;
  }
  cout << ans%mod << endl;

  return 0;
}