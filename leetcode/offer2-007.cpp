/*
 *@File Name          :offer2-007.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:35
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    if ((l == i + 1 || nums[l] != nums[l - 1]) && (r == n - 1 || nums[r] != nums[r + 1]))
                        ans.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                } else if (nums[l] + nums[r] > -nums[i])
                    r--;
                else l++;
            }
        }
        return ans;
    }
};