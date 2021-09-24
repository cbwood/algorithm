//
// Created by cb on 2021/9/23.
//

#include "vector"
#include "climits"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int tmp = 0;
        for(auto &x: nums){
            tmp += x;
            ans = max(ans, tmp);
            tmp = max(tmp, 0);
        }return ans;
    }
};
