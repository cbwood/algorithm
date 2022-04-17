/*
 *@File Name          :offer2-011.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/14 16:54
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map_sums;
        int size_nums = nums.size();
        int sumx = 0;
        int ans = 0;
        for (int i = 0; i < size_nums; i++) {
            if (nums[i] == 0)
                sumx -= 1;
            else sumx += 1;
            if (map_sums.count(sumx)) {
                ans = max(ans, i - map_sums[sumx]);
            } else {
                map_sums[sumx] = i;
            }
            if (sumx == 0) ans = max(ans, i + 1);
        }
        return ans;
    }
};