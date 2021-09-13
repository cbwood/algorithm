#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> vc;
    int len, clen;
    MedianFinder() {
        len = 0;
        clen=0;
    }
    void addNum(int num) {
        vc.push(num);
        len++;
        clen++;
        int k = (len+1)/2;
        while(clen>k){
            vc.pop();
            clen--;
        }
    }
    
    double findMedian() {
        if(len&1)
            return vc.top();
        double tmp = vc.top();
        vc.pop();
        double ans = (tmp+vc.top())/2;
        vc.push(tmp);
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */