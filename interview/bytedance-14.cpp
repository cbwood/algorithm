/*
 *@File Name          :bytedance-14.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/28 11:24
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;
vector<int> a;

struct cmp {
  bool operator()(int& i, int& j) { return a[i] > a[j]; }
};

int main() {
  int n, k;
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  priority_queue<int, deque<int>, cmp> que;
  int                                  ans  = INT_MIN;
  int                                  sumx = 0;
  for (int i = 0; i <= k; i++) {
    que.push(i);
    sumx += a[i];
  }
  int l = 0, r = k + 1;
  ans = sumx - a[que.top()];
  while (r < n) {
    que.push(r);
    sumx += a[r];
    sumx -= a[l];
    l++;
    r++;
    while (que.top() < l) { que.pop(); }
    ans = max(ans, sumx - a[que.top()]);
  }
  cout << ans << endl;
}