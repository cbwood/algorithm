//
// Created by cb on 2021/9/15.
//
#include "iostream"
using namespace std;

class Solution {
public:
    int multiply(int A, int B) {
        if(B == 1) return A;
        if(B&1) return multiply(A,B-1)+A;
        int k = multiply(A, B/2);
        return k+k;
    }
};

int main(){
    Solution so;
    cout<<so.multiply(3,4);
    return 0;
}