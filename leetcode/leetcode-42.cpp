/*
 *@File Name          :leetcode-42.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/28 9:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> preMax(n, INT_MIN);
        for (int i = 1; i < n; i++)
            preMax[i] = max(preMax[i - 1], height[i - 1]);
        int postMax = INT_MIN;
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            postMax = max(postMax, height[i + 1]);
            ans += min(min(postMax, preMax[i]) - height[i], 0);
        }
        return ans;
    }
};