/*
 *@File Name          :offer2-071.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/1 8:13
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include <ctime>
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
 public:
  vector<int> pre;
  Solution(vector<int>& w) : pre(w.size(), 0) {
    pre[0] = w[0];
    for (int i = 1; i < w.size(); ++i) pre[i] = pre[i - 1] + w[i];
    srand(unsigned(time(nullptr)));
  }

  int pickIndex() {
    int n = rand() % pre.back() + 1;
    return std::lower_bound(pre.begin(), pre.end(), n) - pre.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */