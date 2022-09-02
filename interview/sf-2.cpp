#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  vector<int>         a(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    e[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) { cin >> a[i]; }
  //   dfs(1, 0, e, a);
  long long  ans = 0;
  queue<int> que;
  que.push(1);
  vector<vector<int>> t;
  t.push_back({1});
  while (!que.empty()) {
    int         sz = que.size();
    vector<int> tmp;
    for (int i = 0; i < sz; i++) {
      int cur = que.front();
      que.pop();
      for (auto& x : e[cur]) {
        tmp.push_back(x);
        que.push(x);
      }
    }
    t.push_back(tmp);
  }
  long long k = 0;
  for (int i = t.size() - 1; i >= 0; --i) {
    long long maxi = LONG_LONG_MIN;
    long long mini = LONG_LONG_MAX;
    set<int>  se;
    for (auto& x : t[i]) {
      maxi = max(maxi, 1LL * x+k);
      mini = min(mini, 1LL * x+k);
    }
    if(maxi > 0){
        ans += maxi;
        k += maxi;
    }
    if(mini <0)
        ans -= mini, k+= mini;
  }
  cout << ans << endl;
  return 0;
}