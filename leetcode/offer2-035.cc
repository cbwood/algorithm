/*
 *@File Name          :offer2-035.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/2 9:58
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "algorithm"
#include "climits"

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        int n = timePoints.size();
        std::sort(timePoints.begin(), timePoints.end());
        int m1 = ((timePoints[0][0] - '0') * 10 + timePoints[0][1] - '0' + 24) * 60 +
                 (timePoints[0][3] - '0') * 10 + timePoints[0][4] - '0';
        int m2 = ((timePoints[n - 1][0] - '0') * 10 + timePoints[n - 1][1] - '0') * 60 +
                 (timePoints[n - 1][3] - '0') * 10 + timePoints[n - 1][4] - '0';
        int ans = m1 - m2;
        for (int i = 1; i < n; i++) {
            m1 = ((timePoints[i][0] - '0') * 10 + timePoints[i][1] - '0') * 60 +
                 (timePoints[i][3] - '0') * 10 + timePoints[i][4] - '0';
            m2 = ((timePoints[i - 1][0] - '0') * 10 + timePoints[i - 1][1] - '0') * 60 +
                 (timePoints[i - 1][3] - '0') * 10 + timePoints[i - 1][4] - '0';
            ans = min(ans, m1 - m2);
        }
        return ans;
    }
};