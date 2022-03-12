/*
 *@File Name          :leetcode-2049.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/11 14:12
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int ans;
    long long maxd;
    int n;

    int dfs(vector<vector<int>> &e, int cur) {
        int num = 1;
        long long anst = 1;
        int k;
        for (auto &x: e[cur]) {
            k = dfs(e, x);
            anst = anst * k;
            num += k;
        }
        anst *= max(1, n - num);
        if (anst > maxd) {
            maxd = anst;
            ans = 0;
        }
        if (maxd == anst)
            ans++;
        return num;

    }

    int countHighestScoreNodes(vector<int> &parents) {
        n = parents.size();
        vector<vector<int>> e(n);
        for (int i = 1; i < n; i++)
            e[parents[i]].push_back(i);
        ans = 0;
        maxd = 0;
        dfs(e, 0);
        return ans;
    }
};