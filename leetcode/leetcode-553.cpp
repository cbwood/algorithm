/*
 *@File Name          :leetcode-553.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/27 9:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        string ans = to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums.size() > 2 && i == 1)
                ans += "/(";
            else ans += "/";
            ans += to_string(nums[i]);
            if (nums.size() > 2 && i == nums.size() - 1)
                ans += ")";
        }
        return ans;
    }
};