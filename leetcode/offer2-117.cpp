/*
 *@File Name          :offer2-117.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/6 15:01
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "string"
#include "vector"
using namespace std;
class Solution {
 public:
  vector<int> f;

  int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
  }

  void merge(int x, int y) {
    x    = find(x);
    y    = find(y);
    f[x] = y;
  }

  bool check(const string& a, const string& b, int len) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
      if (a[i] != b[i]) cnt++;
      if (cnt > 2) return false;
    }
    return true;
  }

  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();
    f.resize(n + 1, 0);
    for (int i = 0; i < n + 1; i++) f[i] = i;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = find(i);
        int y = find(j);
        if (x == y) continue;
        if (check(strs[i], strs[j], m)) f[x] = y;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += f[i] == i;

    return ans;
  }
};