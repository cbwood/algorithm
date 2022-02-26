/*
 *@File Name          :leetcode-2016.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/26 8:44
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int> &nums) {
        int ans = -1;
        int minx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - minx > 0) {
                if (nums[i] - minx > ans)
                    ans = nums[i] - minx;
            } else minx = nums[i];
        }
        return ans;
    }
};