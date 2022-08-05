/*
 *@File Name          :offer-09-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/8/4 10:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "stack"
using namespace std;

class CQueue {
 public:
  CQueue() {}

  void appendTail(int value) { sta1.push(value); }

  int deleteHead() {
    if (sta2.empty()) {
      while (!sta1.empty()) {
        sta2.push(sta1.top());
        sta1.pop();
      }
    }
    int x = -1;
    if (!sta2.empty()) {
      x = sta2.top();
      sta2.pop();
    }

    return x;
  }

 private:
  stack<int> sta1, sta2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */