//
// Created by cb on 2021/12/20.
//
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int cnt=0;
        for(auto &x: nums){
            if(cnt == 0){
                ans = x;
            }if(x == ans) cnt++;
            else if(x != ans) cnt--;
        }
        cnt=0;
        for(auto &x: nums){
            if(x == ans)
                cnt++;
        }if(cnt <= nums.size()/2) ans=-1;
        return ans;
    }
};