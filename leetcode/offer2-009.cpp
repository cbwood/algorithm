/*
 *@File Name          :offer2-009.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        int l = 0, r = 0;
        int pre_sum = 1;
        while (r < n) {
            pre_sum *= nums[r];
            while (pre_sum >= k && l <= r) {
                pre_sum /= nums[l];
                l++;
            }
            r++;
            ans += r - l;
        }
        return ans;
    }
};