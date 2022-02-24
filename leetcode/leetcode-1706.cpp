/*
 *@File Name          :leetcode-1706.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/24 9:13
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int x = i;
            bool check = true;
            for (int j = 0; j < m; j++) {
                if (grid[j][x] == 1) {
                    if (x == n - 1 || grid[j][x + 1] == -1) {
                        check = false;
                        break;
                    }
                    x++;
                } else {
                    if (x == 0 || grid[j][x - 1] == 1) {
                        check = false;
                        break;
                    }
                    x--;
                }
            }
            if (check)
                ans[i] = x;
        }
        return ans;
    }
};