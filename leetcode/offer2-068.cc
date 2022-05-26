/*
 *@File Name          :offer2-068.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/26 10:30
 *@Description        :
 *@Function List      :
 *@History            :
 */


#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};