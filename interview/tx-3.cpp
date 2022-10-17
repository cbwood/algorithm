#include <bits/stdc++.h>

using namespace std;

int main() {
  int        n;
  deque<int> que;
  cin >> n;
  int m = n;
  while (m--) {
    int x;
    cin >> x;
    que.push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    int cur;
    if (i & 1) {
      if (que.front() > que.back()) {
        cur = que.front();
        que.pop_front();
      } else {
        cur = que.back();
        que.pop_back();
      }
    } else {
      if (que.front() < que.back()) {
        cur = que.front();
        que.pop_front();
      } else {
        cur = que.back();
        que.pop_back();
      }
    }
    cout << cur << " ";
  }
  cout << endl;
  return 0;
}