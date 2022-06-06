/*
 *@File Name          :offer2-075.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/6 8:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "map"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> ma;
    for (auto& x : arr1) ma[x]++;
    int k = 0;
    for (auto& x : arr2) {
      int t = ma[x];
      for (int i = 0; i < t; ++i) arr1[k++] = x;
      if (t) ma.erase(x);
    }
    for (auto& x : ma) {
      int t = x.second;
      for (int i = 0; i < t; ++i) arr1[k++] = x.first;
    }
    return arr1;
  }
};