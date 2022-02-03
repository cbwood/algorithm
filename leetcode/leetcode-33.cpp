/*
 * @File Name          :leetcode-33.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/3 16:10
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[0] < nums[mid]) {
                if (nums[l] <= target && target <= nums[mid])
                    r = mid - 1;
                else l = mid + 1;
            } else {
                if (target >= nums[mid] && target <= nums[r])
                    l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};