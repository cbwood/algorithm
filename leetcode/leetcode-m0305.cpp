//
// Created by cb on 2021/9/13.
//

#include "stack"
using namespace std;

class SortedStack {
public:
    SortedStack() {

    }

    void push(int val) {
        stack<int> tmp;
        while(!stac.empty() && stac.top() < val){
            tmp.push(stac.top());
            stac.pop();
        }stac.push(val);
        while(!tmp.empty()){
            stac.push(tmp.top());
            tmp.pop();
        }
    }

    void pop() {
        if(stac.empty()) return;
        stac.pop();
    }

    int peek() {
        if(stac.empty()) return -1;
        return stac.top();
    }

    bool isEmpty() {
        return stac.empty();
    }

private:
    stack<int> stac;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */