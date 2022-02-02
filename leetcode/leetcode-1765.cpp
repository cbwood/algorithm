/*
 * @File Name          :leetcode-1765.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/29 10:35
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "queue"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    que.emplace(i, j);
                }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!que.empty()) {
            pair<int, int> p = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int sx = p.first + dx[i];
                int sy = p.second + dy[i];
                if (sx >= 0 && sy >= 0 && sx < m && sy < n && ans[sx][sy] == -1) {
                    ans[sx][sy] = ans[p.first][p.second] + 1;
                    que.emplace(sx, sy);
                }
            }
        }
        return ans;
    }
};