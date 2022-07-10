/*
 *@File Name          :leetcode-w301-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/7/10 11:54
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"
using namespace std;

class SmallestInfiniteSet {
 public:
  map<int, int> ma;
  SmallestInfiniteSet() {}

  int popSmallest() {
    for (int i = 1;; i++) {
      if (ma[i] == 0) {
        ma[i] = -1;
        return i;
      }
    }
  }

  void addBack(int num) { ma[num] = 0; }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */