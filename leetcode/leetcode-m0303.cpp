//
// Created by cb on 2021/9/13.
//
#include "vector"
#include "stack"
using namespace std;

class StackOfPlates {
public:
    StackOfPlates(int cap) {
        capacity = cap;
    }

    void push(int val) {
        if(capacity == 0) return;
        if(stacks.empty() || stacks.back().size() == capacity){
            stacks.emplace_back(stack<int>());
        }
        stacks.back().push(val);
    }

    int pop() {
        if(capacity == 0 || stacks.empty()) return -1;
        int k = stacks.back().top();;
        stacks.back().pop();
        if(stacks.back().empty())
            stacks.pop_back();
        return k;
    }

    int popAt(int index) {
        if(capacity == 0 || stacks.size() <= index || stacks[index].empty())
            return -1;
        int k = stacks[index].top();
        stacks[index].pop();
        if(stacks[index].empty()){
            stacks.erase(stacks.begin()+index);
        }return k;
    }

private:
    int capacity;
    vector<stack<int>> stacks;
};