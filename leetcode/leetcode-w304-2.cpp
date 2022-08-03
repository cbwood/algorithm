/*
 *@File Name          :leetcode-w304-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/31 11:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    std::sort(grades.begin(), grades.end());
    int ans  = 1;
    int n    = grades.size();
    int prex = grades[0];
    int prek = 1;
    int sumx = 0;
    int k    = 0;
    for (int i = 1; i < n; i++) {
      sumx += grades[i];
      k++;
      if (sumx > prex && k > prek) {
        prex = sumx;
        prek = k;
        ans++;
        sumx = 0;
        k    = 0;
      }
    }
    return ans;
  }
};