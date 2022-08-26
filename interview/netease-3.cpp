/*
 *@File Name          :netease-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/20 15:10
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

int bitsa[10], bitsb[10];
int ans;

void dfs(int sumx, int a, int b, int ka, int kb) {
  if (ka < 0 && kb < 0) {
    if (sumx < ans && (a && b) && (a % b == 0 || b % a == 0)) ans = sumx;
    return;
  }

  dfs(sumx, a, b, ka - 1, kb - 1);

  if (ka >= 0) { dfs(sumx - 1, a * 10 + bitsa[ka], b, ka - 1, kb); }
  if (kb >= 0) { dfs(sumx - 1, a, b * 10 + bitsb[kb], ka, kb - 1); }
  if (ka >= 0 && kb >= 0) {
    dfs(sumx - 2, a * 10 + bitsa[ka], b * 10 + bitsb[kb], ka - 1, kb - 1);
  }
}

int main() {
  int a, b;
  cin >> a >> b;
  int ka = 0, kb = 0;
  while (a) {
    bitsa[ka++] = a % 10;
    a /= 10;
  }

  while (b) {
    bitsb[kb++] = b % 10;
    b /= 10;
  }
  ans = INT_MAX;
  dfs(ka + kb, 0, 0, ka - 1, kb - 1);
  if (ans == INT_MAX) ans = -1;

  cout << ans << endl;
  return 0;
}