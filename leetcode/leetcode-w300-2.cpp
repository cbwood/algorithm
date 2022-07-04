/*
 *@File Name          :leetcode-w300-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/3 10:51
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int                 k = min(m / 2, n / 2) + 1;
    int                 x = 0, y = 0;
    vector<vector<int>> a(m, vector<int>(n));
    while (k--) {
      if (y >= n) break;
      for (int i = y; i < n; i++) {
        if (head) {
          a[x][i] = head->val;
          head    = head->next;
        } else
          a[x][i] = -1;
      }
      x++;
      if (x >= m) break;
      for (int i = x; i < m; i++) {
        if (head) {
          a[i][n - 1] = head->val;
          head        = head->next;
        } else
          a[i][n - 1] = -1;
      }
      n--;
      if (n - 1 < y) break;
      for (int i = n - 1; i >= y; i--) {
        if (head) {
          a[m - 1][i] = head->val;
          head        = head->next;
        } else
          a[m - 1][i] = -1;
      }
      m--;
      if (m - 1 < x) break;
      for (int i = m - 1; i >= x; i--) {
        if (head) {
          a[i][y] = head->val;
          head    = head->next;
        } else
          a[i][y] = -1;
      }
      y++;
    }
    return a;
  }
};