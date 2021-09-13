#include<bits/stdc++.h>
using namespace std;

class CQueue {
    stack<int> in,out;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        in.push(value);
    }
    
    int deleteHead() {
        if(out.empty()){
            if(in.empty()) return -1;
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }int ans = out.top();
        out.pop();
        return ans;
    }
};
