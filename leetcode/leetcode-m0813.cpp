//
// Created by cb on 2021/9/16.
//

#include "vector"
#include "algorithm"
#include "climits"

using namespace std;

class Solution {
public:
    int pileBox(vector<vector<int>> &box) {
        sort(box.begin(), box.end(), cmp);
        vector<int> pre{-1, -1, -1};
        vector<int> dp;
        int ans = 0;
        dp.push_back(box[0][2]);
        ans = dp[0];
        for (int i = 1; i < box.size(); i++) {
            dp.push_back(box[i][2]);
            ans = max(ans, dp[i]);
            for (int j = i - 1; j >= 0; j--) {
                if (box[i][0] < box[j][0] && box[i][1] < box[j][1] && box[i][2] < box[j][2] && dp[i]<dp[j]+box[i][2]) {
                    dp[i] = dp[j] + box[i][2];
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }

    static bool cmp(const vector<int> &p, const vector<int> &q) {
        return (p[2] > q[2]);
    }
};