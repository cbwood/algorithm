/*
 *@File Name          :leetcode-704.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/28 10:08
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};