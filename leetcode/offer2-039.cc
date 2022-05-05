/*
 *@File Name          :offer2-039.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/5 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> sta;
        int heights_size = heights.size();
        vector<int> left_less(heights_size);
        for (int i = 0; i < heights_size; i++) {
            while (!sta.empty() && heights[i] <= heights[sta.top()])
                sta.pop();
            if (sta.empty())
                left_less[i] = -1;
            else left_less[i] = sta.top();
            sta.push(i);
        }
        int ans = 0;
        sta = stack<int>();
        int right_greater = heights_size;
        for (int i = heights_size - 1; i >= 0; --i) {
            while (!sta.empty() && heights[i] <= heights[sta.top()])
                sta.pop();
            if (sta.empty())
                right_greater = heights_size;
            else right_greater = sta.top();
            sta.push(i);
            ans = max(ans, (right_greater - left_less[i] - 1) * heights[i]);
        }
        return ans;
    }
};