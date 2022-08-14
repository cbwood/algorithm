/*
 *@File Name          :meituan-5.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/6 10:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;
//char   ans;
//string ss    = "MeiTuannauTieMwow";
//bool   flag = false;
//
//void dfs(long long n, long long k) {
//  if(n <= 17){
//    ans  = t[k-1];
//    flag = true;
//    return;
//  }
//  if (k > n) {
//    if (k - n == 1 || k - n == 3) {
//      ans  = 'w';
//      flag = true;
//      return;
//    }else {
//      ans  = 'o';
//      flag = true;
//      return;
//    }
//  }
//  if(flag) return ;
//  long long tmp = (n-3)/2;
//  dfs(tmp,k-tmp);
//}
//
//int main() {
//  long long n;
//  int       t;
//  cin >> t;
//  while (t--) {
//    cin >> n;
////    long long k = 7;
////    while (k < n) { k = k * 2 + 3; }
////    dfs(n, k);
////    cout << ans << endl;
//    while ((long long)ss.size() < n){
//      string tmp = ss;
//      std::reverse(tmp.begin(), tmp.end());
//      ss += tmp +"wow";
//    }
//    cout<<ss[n-1]<<endl;
//  }
//  return 0;
//}

string            ss  = "MeiTuannauTieMwow";
string            ss1 = "wowMeiTuannauTieMwow";
typedef long long LL;

int main() {
  int t;
  cin >> t;
  while (t--) {
    LL n;
    cin >> n;
    if (n <= ss.size()) {
      cout << ss[n - 1] << endl;
      continue;
    }
    n = (n - (LL)ss.size() - 1) % ((LL)ss1.size());
    cout << ss1[n] << endl;
  }
}
