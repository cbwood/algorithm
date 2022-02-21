/*
 * @File Name          :leetcode-1219.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/5 12:37
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include <cstring>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    bool vis[250];
    int n, m;

    int dfs(int x, int y, vector<vector<int>> &grid) {
        int ans = grid[x][y];

        for (int i = 0; i < 4; i++) {
            int sx = x + dx[i];
            int sy = y + dy[i];
            if (sx >= 0 && sy >= 0 && sx < n && sy < m && !vis[sx * 15 + sy] && grid[sx][sy] != 0) {
                vis[sx * 15 + sy] = true;
                ans = max(ans, dfs(sx, sy, grid) + grid[x][y]);
                vis[sx * 15 + sy] = false;
            }
        }
        return ans;
    }

    int getMaximumGold(vector<vector<int>> &grid) {
        int ans = 0;
        n = grid.size();
        if (n == 0) return 0;
        m = grid[0].size();
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]) {
                    vis[i * 15 + j] = true;
                    int tmp = dfs(i, j, grid);
                    ans = max(ans, tmp);
                    vis[i * 15 + j] = false;
                }
        return ans;
    }
};