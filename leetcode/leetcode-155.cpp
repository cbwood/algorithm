/*
 *@File Name          :leetcode-155.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/30 10:38
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "stack"

using namespace std;

class MinStack {
private:
    stack<long long> sta;
    long long minx;
public:

    MinStack() {
        minx = 0;
    }

    void push(int val) {
        if (sta.empty()) {
            sta.push(0);
            minx = val;
        } else {
            sta.push(val - minx);
            if (val < minx) {
                minx = val;
            }
        }
    }

    void pop() {
        long long dif = sta.top();
        sta.pop();
        if (dif < 0) {
            minx = minx - dif;
        }
    }

    int top() {
        long long dif = sta.top();
        if (dif < 0)
            return minx;
        return dif + minx;
    }

    int getMin() {
        return sta.empty() ? -1 : minx;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */