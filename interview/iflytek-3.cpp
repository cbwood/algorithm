/*
 *@File Name          :iflytek-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/23 19:58
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

const int        comb = 184756;
set<vector<int>> se;

inline pair<int, int> cao(int k) {
  if (k == 1) return {1, 0};
  if (k <= 3) return {2, k - 2};
  if (k <= 6) return {3, k - 4};
  if (k <= 10) return {4, k - 7};
}

vector<int> sc(5, 0);

void gao(vector<int>& t, int cur) {
  if (cur == 10) {
    std::sort(sc.begin(), sc.end());
    se.insert(sc);
    return;
  }
  pair<int, int> p = cao(t[cur]);

  sc[p.first] += 3;
  gao(t, cur + 1);
  sc[p.first] -= 3;

  sc[p.first] += 1;
  sc[p.second] += 1;
  gao(t, cur + 1);
  sc[p.first] -= 1;
  sc[p.second] -= 1;

  sc[p.second] += 3;
  gao(t, cur + 1);
  sc[p.second] -= 3;
}

int main() {
  vector<int> tmp;

  vector<int> t;
  for (int i = 0; i < 10; i++) t.push_back(i + 1);
  gao(t, 0);

  cout << se.size() << endl;

  int a;

  vector<int> b(5, 0);
  cin >> a;
  for (int i = 0; i < 5; i++) cin >> b[i];

  std::sort(b.begin(), b.end());
  if (se.count(b) == 1)
    cout << "yes"
         << " ";
  else
    cout << "no"
         << " ";

  //  if(a == comb)
  //    cout<<"yes"<<" ";
  //  else cout<<"no"<<" ";
  //  cout<<"yes"<<endl;
  return 0;
}