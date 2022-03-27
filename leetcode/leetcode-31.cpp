/*
 *@File Name          :leetcode-31.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 11:01
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size() - 1;
        int i = n - 1, j = n;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            while (j >= 0 && nums[i] >= nums[j])
                j--;
            swap(nums[i], nums[j]);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
};