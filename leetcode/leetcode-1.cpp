/*
 * @File Name          :leetcode-1.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/6 9:42
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> ma;
        for (int i = 0; i < nums.size(); i++) {
            if (ma[target - nums[i]] != 0 && ma[target - nums[i]] != i + 1) {
                int l = i;
                int r = ma[target - nums[i]] - 1;
                if (l > r) swap(l, r);
                return {l, r};
            }
            ma[nums[i]] = i + 1;
        }
        return {0, 1};
    }
};