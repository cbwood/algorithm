//
// Created by cb on 2021/9/23.
//

#include "vector"
#include "algorithm"
#include "climits"
#include "iostream"

using namespace std;

class Solution {
public:
    vector<int> pondSizes(vector<vector<int>> &land) {
        vector<int> ans;
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[i].size(); ++j) {
                if (land[i][j] == 0)
                    ans.push_back(dfs(land, i, j));
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    int dfs(vector<vector<int>> &land, int x, int y) {
        land[x][y] = 1;
        int ans = 0;
        for (int i = 0; i < 8; i++) {
            int sx = x + dx[i];
            int sy = y + dy[i];
            if (sx >= 0 && sy >= 0 && sx < land.size() && sy < land[0].size() && land[sx][sy] == 0) {
                ans += dfs(land, sx, sy);
            }
        }
        return 1 + ans;
    }

private:
    int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
};