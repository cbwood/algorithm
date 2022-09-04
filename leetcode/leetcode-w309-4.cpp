#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<pair<long long, long long>> room(n);
    vector<int>                        cnt(n, 0);
    int                                ans = 0;
    for (int i = 0; i < n; i++) room[i] = {-1, -1};
    sort(meetings.begin(), meetings.end(),
         [](vector<int>& p, vector<int>& q) { return p[0] < q[0]; });
    for (auto& x : meetings) {
      int idx    = -1;
      int minxid = 0;
      for (int i = 0; i < n; i++) {
        if (room[i].second <= x[0]) {
          idx = i;
          break;
        }
        if (room[minxid].second > room[i].second) { minxid = i; }
      };

      if (idx == -1) {
        long long dif      = room[minxid].second - x[0];
        room[minxid] = {room[minxid].second, 1LL * x[1] + dif};
        cnt[minxid]++;
        if (cnt[minxid] > cnt[ans] ||
            (cnt[minxid] == cnt[ans] && minxid < ans)) {
          ans = minxid;
        }
      } else {
        room[idx] = {x[0], x[1]};
        cnt[idx]++;
        if (cnt[idx] > cnt[ans] || (cnt[idx] == cnt[ans] && idx < ans)) {
          ans = idx;
        }
      }
    }
    for (int i = 0; i < n; i++) { cout << cnt[i] << " "; }
    cout << endl;
    return ans;
  }
};