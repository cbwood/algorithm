/*
 *@File Name          :leetcode-w289-3.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 11:12
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include <utility>

#include "queue"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;


class Solution {
public:
    int ans;
    vector<vector<int>> e;
    string t;

    int dfs(int cur, char pre) {
        char ch = t[cur];
        vector<int> tmp;
        for (auto &x: e[cur]) {
            int y = dfs(x, ch);
            tmp.push_back(y);
        }
        if (tmp.size() == 1) {
            ans = max(ans, tmp[0] + 1);
        } else if (tmp.size() >= 2) {
            std::sort(tmp.begin(), tmp.end(), greater<>());
            ans = max(ans, tmp[0] + tmp[1] + 1);
        }
        if (pre == ch) return 0;
        if (tmp.size() == 0) return 1;
        return tmp[0] + 1;
    }

    int longestPath(vector<int> &parent, string s) {
        t = std::move(s);
        ans = 1;
        int n = parent.size();
        e = vector<vector<int>>(n);
        for (int i = 1; i < n; i++) {
            e[parent[i]].push_back(i);
        }
        dfs(0, '0');
        return ans;
    }
};