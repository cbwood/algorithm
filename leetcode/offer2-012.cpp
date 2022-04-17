/*
 *@File Name          :offer2-012.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 9:34
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int nums_size = nums.size();
        int post_sum = 0;
        for (int i = nums_size - 1; i >= 0; --i) {
            post_sum += nums[i];
        }
        int pre_sum = 0;
        for (int i = 0; i < nums_size; i++) {
            post_sum -= nums[i];
            if (pre_sum == post_sum) {
                return i;
            }
            pre_sum += nums[i];
        }
        return -1;
    }
};