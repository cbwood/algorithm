//
// Created by cb on 2021/9/16.
//

#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    int countEval(string s, int result) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int i = 0; i < n; i += 2) {
            int k = s[i] - '0';
            dp[i][i][0] = 1 - k;
            dp[i][i][1] = k;
        }
        for (int step = 0; step < n; step += 2)
            for (int i = 0; i + step < n; i += 2)
                for (int j = i + 1; j < i + step; j += 2) {
                    int l0 = dp[i][j - 1][0], l1 = dp[i][j - 1][1];
                    int r0 = dp[j + 1][i + step][0], r1 = dp[j + 1][i + step][1];
                    if (s[j] == '&') {
                        dp[i][i + step][1] += l1 * r1;
                        dp[i][i + step][0] += l1 * r0 + l0 * r0 + l0 * r1;
                    } else if (s[j] == '|') {
                        dp[i][i + step][1] += l1 * r1 + l1 * r0 + l0 * r1;
                        dp[i][i + step][0] += l0 * r0;
                    } else if (s[j] == '^') {
                        dp[i][i + step][1] += l1 * r0 + l0 * r1;
                        dp[i][i + step][0] += l0 * r0 + l1 * r1;
                    }
                }
        return dp[0][n - 1][result];
    }
};

int main() {
    Solution so;
    cout << so.countEval("1^0|0|1", 0);
    return 0;
}