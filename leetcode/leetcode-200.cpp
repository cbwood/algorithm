/*
 * @File Name          :leetcode-200.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/5 14:36
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;


class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int x, int y, vector<vector<char>> &grid) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int sx = x + dx[i];
            int sy = y = dy[i];
            if (sx >= 0 && sy >= 0 && sx < n && sy < m && grid[sx][sy] == '1') {
                dfs(sx, sy, grid);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;

                }
        return ans;
    }
};