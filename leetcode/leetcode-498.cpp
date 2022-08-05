/*
 *@File Name          :leetcode-498.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/5 9:09
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<int> ans(m * n);

    int k = 0;
    for (int i = 0; i < m; i++) {
      int         a = i, b = 0;
      vector<int> t;
      while (a >= 0 && b < n) {
        t.push_back(mat[b][a]);
        a--;
        b++;
      }
      if (k & 1) std::reverse(t.begin(), t.end());
      k++;
      ans.insert(ans.end(), t.begin(), t.end());
    }
    for (int i = 1; i < n; i++) {
      int         a = i, b = m - 1;
      vector<int> t;

      while (a < n && b >= 0) {
        t.push_back(mat[a][b]);
        a++;
        b--;
      }
      if (k & 1) std::reverse(t.begin(), t.end());
      k++;
      ans.insert(ans.end(), t.begin(), t.end());
    }
    return ans;
  }
};