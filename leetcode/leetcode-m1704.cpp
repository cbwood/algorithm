//
// Created by cb on 2021/9/24.
//


#include "vector"
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 1; i <= n; i++){
            ans ^= i;
            ans ^= nums[i-1];
        }return ans;
    }
};