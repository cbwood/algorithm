/*
 *@File Name          :lccup-4.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 14:31
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "bits/stdc++.h"

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int dp[102][102];
    bool vis[102][102];
    map<char, int> ma;
    int ans;

    int dfs(int sx, int sy, int ex, int ey, int st, vector<string> &matrix) {
        if (sx == ex && sy == ey) {
            if (st < ans)
                ans = st;
            return st;
        }
        if (dp[sx][sy] != INT_MAX && dp[sx][sy] != INT_MAX - 1) return dp[sx][sy];
        if (ans == 0) return dp[sx][sy];
        if (ans <= st) return dp[sx][sy];
        for (int i = 0; i < 4; i++) {
            int idx = (i + ma[matrix[sx][sy]]) % 4;
            int nx = sx + dx[idx];
            int ny = sy + dy[idx];
            if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                dp[sx][sy] = min(dp[sx][sy], dfs(nx, ny, ex, ey, st + (i != 0), matrix));
                vis[nx][ny] = 0;
            }
        }
        return dp[sx][sy];
    }

    void dfs(int sx, int sy, vector<string> &matrix,
             priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> &que, int st) {
        int idx = ma[matrix[sx][sy]];
        int nx = sx + dx[idx];
        int ny = sy + dy[idx];
        if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            que.push({st, {nx, ny}});
            dfs(nx, ny, matrix, que, st);
        }
    }

    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end) {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                dp[i][j] = INT_MAX;
        ma['v'] = 0;
        ma['^'] = 1;
        ma['<'] = 3;
        ma['>'] = 2;
        ans = INT_MAX;
//        dfs(start[0], start[1], end[0], end[1], 0, matrix);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> que;
        que.push({0, {start[0], start[1]}});
        vis[start[0]][start[1]] = 1;
        while (!que.empty()) {
            pair<int, pair<int, int>> t = que.top();
            que.pop();
            if (t.second.first == end[0] && t.second.second == end[1]) {
                return t.first;
            }
            int sx = t.second.first;
            int sy = t.second.second;
            for (int i = 0; i < 4; i++) {
                int idx = (i + ma[matrix[sx][sy]]) % 4;
                int nx = sx + dx[idx];
                int ny = sy + dy[idx];
                if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({t.first + (i != 0), {nx, ny}});
                    dfs(nx, ny, matrix, que, t.first + (i != 0));
//                vis[sx][sy][idx] = 0;
                }
            }
        }
        return ans;
    }
};
/*
 * [">>v"
 * ,"v^<"
 * ,"<><"]
 */