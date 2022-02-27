/*
 *@File Name          :leetcode-300-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/27 9:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> vec;
        int ans = 1;
        for (auto &x: nums) {
            int k = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
            if (k >= vec.size())
                vec.push_back(x);
            else
                vec[k] = x;
            if (ans < k + 1)
                ans = k + 1;
        }
        return ans;
    }
};