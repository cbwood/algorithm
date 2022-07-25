/*
 *@File Name          :iflytek-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/23 19:39
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

const double pi = 3.1415927;

double ham(int i, int n) { return 0.5 * (1.0 - cos(2 * pi * i / n)); }

int gao(double x) {
  if (x >= 0) return int(x + 0.5);
  return int(x - 0.5);
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    double t = a[i] * ham(i, n);
    cout << gao(t) << " ";
  }
  double t = a[n - 1] * ham(n - 1, n);

  cout << gao(t) << endl;
  return 0;
}