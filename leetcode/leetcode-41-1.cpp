/*
 *@File Name          :leetcode-41-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/27 9:02
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] <= n && nums[i] >= 1 && nums[nums[i] - 1] != nums[i]) swap(nums[nums[i] - 1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};