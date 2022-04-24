/*
 *@File Name          :lccup-5.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 14:31
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits//stdc++.h"

using namespace std;

class Solution {
public:
    int getMaximumNumber(vector<vector<int>> &moles) {
        int n = moles.size();
        vector<vector<int>> dp(n + 2, vector<int>(9, 0));
        std::sort(moles.begin(), moles.end());
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        int prex = 0;
//        for (int i = 0; i < 3; i++)
//            for (int j = 0; j < 3; j++) {
//                int st = abs(i - 1) + abs(j - 1);
//                if (st + prex <= moles[0][0])
//                    dp[1][i * 3 + j] = 1;
//            }
        map<int, int> ma;
        int nums = 1;
        for (int i = 0; i < n; i++) {
            if (ma.find(moles[i][0]) == ma.end()) {
                ma[moles[i][0]] = nums++;
            }
            int st = abs(moles[i][1] - 1) + abs(moles[i][2] - 1);
            if (st <= moles[i][0])
                dp[ma[moles[i][0]]][moles[i][1] * 3 + moles[i][2]] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int ii = 0; ii < 3; ii++)
                for (int jj = 0; jj < 3; jj++) {
                    dp[ma[moles[i][0]]][ii * 3 + jj] = max(dp[ma[moles[i][0]]][ii * 3 + jj],
                                                           dp[ma[moles[i][0]] - 1][ii * 3 + jj]);
                }
            for (int ii = 0; ii < 3; ii++)
                for (int jj = 0; jj < 3; jj++) {
                    int st = abs(moles[i][1] - ii) + abs(moles[i][2] - jj);
                    if (st + prex <= moles[i][0])
                        dp[ma[moles[i][0]]][moles[i][1] * 3 + moles[i][2]] = max(
                                dp[ma[moles[i][0]] - 1][ii * 3 + jj] + 1,
                                dp[ma[moles[i][0]]][moles[i][1] * 3 + moles[i][2]]);
                }
            ans = max(dp[ma[moles[i][0]]][moles[i][1] * 3 + moles[i][2]], ans);
            if (i != n - 1 && moles[i][0] != moles[i + 1][0])
                prex = moles[i][0];
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                ans = max(ans, dp[nums - 1][i * 3 + j]);
            }
        return ans;
    }
};