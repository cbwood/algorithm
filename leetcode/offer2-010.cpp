/*
 *@File Name          :offer2-010.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/14 16:28
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0;
        int n = nums.size();
        int pre_sum = 0;
        unordered_map<int, int> ma;
        for (int i = 0; i < n; i++) {
            ma[pre_sum]++;
            pre_sum += nums[i];
            ans += ma[pre_sum - k];
        }
        return ans;
    }
};