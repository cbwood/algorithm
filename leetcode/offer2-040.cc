/*
 *@File Name          :offer2-040.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/5 9:16
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "stack"
#include "string"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string> &matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<int> row(m, 0);
        int ans = 0;
        for (auto &s: matrix) {
            for (int i = 0; i < m; i++) {
                if (s[i] == '0')
                    row[i] = 0;
                else row[i] += 1;
            }
            stack<int> sta;
            vector<int> left(m, 0);
            for (int i = 0; i < m; i++) {
                while (!sta.empty() && row[i] <= row[sta.top()])
                    sta.pop();
                if (sta.empty())
                    left[i] = -1;
                else left[i] = sta.top();
                sta.push(i);
            }

            sta = stack<int>();
            int right;
            for (int i = m - 1; i >= 0; --i) {
                while (!sta.empty() && row[i] <= row[sta.top()])
                    sta.pop();
                if (sta.empty())
                    right = m;
                else right = sta.top();
                sta.push(i);
                ans = max(ans, (right - left[i] - 1) * row[i]);
            }
        }
        return ans;
    }
};