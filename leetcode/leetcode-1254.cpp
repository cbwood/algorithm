/*
 *@File Name          :leetcode-1254.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/11 15:51
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>> &grid, const int &n, const int &m, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        for (int idx = 0; idx < 4; idx++)
            dfs(grid, n, m, i + dx[idx], j + dy[idx]);
    }

    int closedIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            dfs(grid, n, m, i, 0);
            dfs(grid, n, m, i, m - 1);
        }
        for (int j = 0; j < m; j++) {
            dfs(grid, n, m, 0, j);
            dfs(grid, n, m, n - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, n, m, i, j);
                }
            }
        return ans;
    }
};