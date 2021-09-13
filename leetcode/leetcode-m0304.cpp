//
// Created by cb on 2021/9/13.
//

#include "stack"

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }int k = s2.top();
        s2.pop();
        return k;
    }

    /** Get the front element. */
    int peek() {
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s2.empty()&&s1.empty();
    }

private:
      stack<int> s1,s2;
};

int main(){
    return 0;
}