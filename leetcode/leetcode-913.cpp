/*
 * @File Name          :leetcode-913.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/4 9:13
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int dp[100][100][100];

    int catMouseGame(vector<vector<int>> &graph) {
        for (int i = 0; i < 100; i++)
            for(int j = 0; j < 100; j++)
                for(int k = 0; k < 100; k++)
                    dp[k][i][j] = -1;
        return dfs(1, 2, graph, 0);
    }

    //st=0表示mouse该移动
    int dfs(int curMouse, int curCat, vector<vector<int>> &graph, int st) {
        if (dp[st][curCat][curMouse] != -1) return dp[st][curCat][curMouse];
        if (st > 2 * graph.size()) return 0;
        if (curMouse == 0) return 1;
        if (curMouse == curCat) return 2;
        if (st % 2 == 0) {
            int k = 2;
            for (auto &x: graph[curMouse]) {
                int t = dfs(x, curCat, graph, st + 1);
                if (t == 1) {
                    dp[st][curCat][curMouse] = 1;
                    return 1;
                }
                else if (t == 0) k = 0;
            }dp[st][curCat][curMouse] = k;
            return k;
        } else {
            int k = 1;
            for (auto &x: graph[curCat])
                if (x) {
                    int t = dfs(curMouse, x, graph, st + 1);
                    if (t == 2) {
                        dp[st][curMouse][curCat] = 2;
                        return 2;
                    }
                    else if (t == 0) k = 0;
                }dp[st][curCat][curMouse] = k;
            return k;
        }
    }
};
