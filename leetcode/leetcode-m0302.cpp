//
// Created by cb on 2021/9/13.
//

#include "stack"
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> vstack;
    stack<int> mstack;

    MinStack() {

    }

    void push(int x) {
        vstack.push(x);
        if(mstack.empty()){
            mstack.push(x);
        }
        if(x <= mstack.top()){
            mstack.push(x);
        }
    }

    void pop() {
        int k = vstack.top();
        vstack.pop();
        if(k == mstack.top())
            mstack.pop();
    }

    int top() {
        return vstack.top();
    }

    int getMin() {
        return mstack.top();
    }
};