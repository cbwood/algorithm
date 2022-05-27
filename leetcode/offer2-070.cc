/*
 *@File Name          :offer2-070.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/27 9:30
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] != nums[mid ^ 1])
                r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};