/*
 * @File Name          :leetcode-747.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/13 9:09
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int pre = -100, maxx = -1;
        int ans = 0;
        int k = 0;
        for (auto &x: nums) {
            if (x > maxx) {
                pre = maxx;
                maxx = x;
                ans = k;
            } else {
                pre = max(pre, x);
            }
            k++;
        }
        return maxx >= pre * 2 ? ans : -1;
    }
};