//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A, B, C, A.size());
    }

    void move(vector<int>& A, vector<int> &B, vector<int> &C, int n){
        if(n == 1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(A, C, B, n-1);
        C.push_back(A.back());
        A.pop_back();
        move(B, A, C, n-1);
    }
};