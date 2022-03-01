/*
 *@File Name          :leetcode-232.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/1 9:17
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "stack"
#include "algorithm"

using namespace std;

class MyQueue {
private:
    stack<int> st1, st2;
public:
    MyQueue() {
    }

    void push(int x) {
        st1.emplace(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.emplace(st1.top());
                st1.pop();
            }
        }
        int k = st2.top();
        st2.pop();
        return k;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.emplace(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */