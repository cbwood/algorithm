/*
 * @File Name          :leetcode-334.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/12 9:15
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int pre1 = nums[0], pre2 = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > pre2)
                return true;
            else if (nums[i] > pre1)
                pre2 = nums[i];
            else pre1 = nums[i];
        }
        return false;
    }
};

