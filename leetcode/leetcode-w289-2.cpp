/*
 *@File Name          :leetcode-w289-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 10:27
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;

class Solution {
public:
    int get2(int x) {
        int ans = 0;
        while (x % 2 == 0) {
            ans++;
            x >>= 1;
        }
        return ans;
    }

    int get5(int x) {
        int ans = 0;
        while (x % 5 == 0) {
            ans++;
            x /= 5;
        }
        return ans;
    }

    int maxTrailingZeros(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        auto nums2 = grid;
        auto nums5 = grid;
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            int num2 = 0;
            int num5 = 0;
            for (int j = 0; j < m; j++) {
                nums2[i][j] = get2(grid[i][j]);
                nums5[i][j] = get5(grid[i][j]);
                dp[j][0] += nums2[i][j];
                dp[j][1] += nums5[i][j];
                ans = max(ans, min(dp[j][0] + num2, dp[j][1] + num5));
                num2 += nums2[i][j];
                num5 += nums5[i][j];
            }
            num2 = 0;
            num5 = 0;
            for (int j = m - 1; j >= 0; j--) {
                ans = max(ans, min(dp[j][0] + num2, dp[j][1] + num5));
                num2 += nums2[i][j];
                num5 += nums5[i][j];
            }
        }
        for (int i = m - 1; i >= 0; --i)
            dp[i][0] = dp[i][1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int num2 = 0;
            int num5 = 0;
            for (int j = 0; j < m; j++) {

                dp[j][0] += nums2[i][j];
                dp[j][1] += nums5[i][j];
                ans = max(ans, min(dp[j][0] + num2, dp[j][1] + num5));
                num2 += nums2[i][j];
                num5 += nums5[i][j];
            }
            num2 = 0;
            num5 = 0;
            for (int j = m - 1; j >= 0; j--) {
                ans = max(ans, min(dp[j][0] + num2, dp[j][1] + num5));
                num2 += nums2[i][j];
                num5 += nums5[i][j];
            }
        }

        return ans;
    }
};