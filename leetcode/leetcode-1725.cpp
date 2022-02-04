/*
 * @File Name          :leetcode-1725.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/4 15:07
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        int ans = 0;
        int maxl = 0;
        for (auto &x: rectangles) {
            int t = min(x[0], x[1]);
            if (t > maxl) {
                maxl = t;
                ans = 1;
            } else if (t == maxl)
                ans++;
        }
        return ans;
    }
};