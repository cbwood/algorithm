/*
 *@File Name          :360-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/27 15:40
 *@Description        :
 *@Function List      :
 *@History            :
 */

/*
 * 吃鸡组队
 * */

#include "bits/stdc++.h"

using namespace std;

int main() {
  int a, b, c, d;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    int ans = 0;
    ans += min(a, c);
    int tt = min(a, c);
    a -= tt;
    c -= tt;
    ans += b / 2;
    if (b & 1)
      b = 1;
    else
      b = 0;
    ans += min(a / 2, b);
    tt = min(a / 2, b);
    a -= 2 * tt;
    b -= tt;
    ans += a / 4;
    cout << ans + d << endl;
  }

  return 0;
}