//
// Created by cb on 2021/12/21.
//

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int mask = 0;
        int n = nums.size();
        for(int i = 1; i <= n+2+n; i++){
            mask ^= nums[i-1];
            if(i <= n+2)
                nums.push_back(i);
        }
        int xx = mask&(-mask);
        int a=0,b=0;
        for(auto &x: nums){
            if(xx&x) a^= x;
            else b ^= x;
        }vector<int> ans{a,b};
        return ans;
    }
};