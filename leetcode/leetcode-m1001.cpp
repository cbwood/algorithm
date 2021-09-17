//
// Created by cb on 2021/9/16.
//

#include "vector"
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int k = 0;
        for(int i = 0; i < m; i++){
            if(k >= n) break;
            if(B[k] < A[i]){
                A.insert(A.begin()+i, B[k++]);
                A.pop_back();
                m++;
            }
        }while(k < n) A[m++] = B[k++];
    }
};