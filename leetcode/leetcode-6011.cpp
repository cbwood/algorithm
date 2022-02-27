/*
 *@File Name          :leetcode-6011.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/27 10:55
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
#include "cstring"
#include "map"

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps) {
        vector<int> minx(20, INT_MAX / 2);
        for (auto x: tires) {
            long t = x[0];
            for (int i = 1, sumx = 0; t <= changeTime + x[0]; i++) {
                sumx += t;
                minx[i] = min(minx[i], sumx);
                t = t * x[1];
            }
        }
        vector<int> dp(numLaps + 1, INT_MAX);
        dp[0] = -changeTime;
        for (int i = 1; i <= numLaps; i++) {
            for (int j = 1; j <= min(17, i); j++)
                dp[i] = min(dp[i], dp[i - j] + minx[j]);
            dp[i] += changeTime;
        }
        return dp[numLaps];
    }
};