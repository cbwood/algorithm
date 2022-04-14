/*
 *@File Name          :offer2-008.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:43
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sumx = 0;
        int l = 0, r = 0, n = nums.size();
        int ans = INT_MAX;
        while (r < n) {
            sumx += nums[r];
            ++r;
            while (sumx >= target) {
                ans = min(ans, r - l);
                sumx -= nums[l];
                ++l;
            }
        }
        if (ans == INT_MAX) ans = 0;
        return ans;
    }
};