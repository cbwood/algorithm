/*
 *@File Name          :leetcode-661.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/24 8:59
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                int num = 0;
                for (int k = max(0, i - 1); k < min(i + 2, n); k++) {
                    for (int t = max(0, j - 1); t < min(j + 2, m); t++) {
                        sum += img[k][t];
                        num++;
                    }
                }
                ans[i][j] = sum / num;
            }
        }
        return ans;
    }
};