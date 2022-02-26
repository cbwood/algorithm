/*
 *@File Name          :leetcode-54.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/26 8:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        int k = min(m / 2, n / 2) + 1;
        int x = 0, y = 0;
        while (k--) {
            if (y >= n) break;
            for (int i = y; i < n; i++) ans.push_back(matrix[x][i]);
            x++;
            if (x >= m) break;
            for (int i = x; i < m; i++) ans.push_back(matrix[i][n - 1]);
            n--;
            if (n - 1 < y) break;
            for (int i = n - 1; i >= y; i--) ans.push_back(matrix[m - 1][i]);
            m--;
            if (m - 1 < x) break;
            for (int i = m - 1; i >= x; i--) ans.push_back(matrix[i][y]);
            y++;
        }
        return ans;
    }
};