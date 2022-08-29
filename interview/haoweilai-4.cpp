/*
 *@File Name          :haoweilai-4.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 19:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int k = stoi(b.substr(7));
  cout << k << endl;
  a.pop_back();
  a = a.substr(6);
  vector<int> v;
  int         pre = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == ',') {
      v.push_back(stoi(a.substr(pre, i - pre)));
      pre = i + 1;
    }
  }
  v.push_back(stoi(a.substr(pre)));

  std::sort(v.begin(), v.end());
  int minx = INT_MAX;

  int n = v.size();
  for (int i = 0; i < n; i++) {
    if (i && v[i] == v[i - 1]) continue;

    int l = i + 1, r = n - 1;
    while (l < r) {
      int sumx = v[i] + v[l] + v[r];
      if (abs(minx) > abs(sumx - k))
        ;
      minx = sumx - k;
      if (sumx == k) {
        minx = 0;
        break;
      } else if (sumx > k) {
        r++;
      } else {
        l--;
      }
    }
  }
  cout << k + minx << endl;
  return 0;
}