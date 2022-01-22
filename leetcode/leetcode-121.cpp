/*
 * @File Name          :leetcode-121.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/22 10:14
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        int pre = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - pre);
            pre = min(pre, prices[i]);
        }
        return ans;
    }
};