//
// Created by cb on 2021/9/18.
//

#include "iostream"
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n){
            ans += n/5;
            n /= 5;
        }return ans;
    }
};