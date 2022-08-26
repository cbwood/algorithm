/*
 *@File Name          :bytedance-10.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/21 20:47
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum1 += x * (x + 1) / 2;
  }
}