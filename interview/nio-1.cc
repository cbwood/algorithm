/*
 *@File Name          :nio-1.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/1 18:59
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);
    if ((x / gcd(x, y)) & 1)
      cout << "A" << endl;
    else
      cout << "B" << endl;
  }
  return 0;
}