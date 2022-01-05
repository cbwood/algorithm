/*
 * @File Name          :leetcode-53.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/5 11:17
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "climits"
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(auto &x: nums){
            sum += x;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }return ans;
    }
};