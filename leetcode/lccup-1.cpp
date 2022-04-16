/*
 *@File Name          :lccup-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/16 14:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int ansx;

    void dfs(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit, int k,
             int ansy, int sumx) {
        if (k == cookbooks.size()) {
            if (ansy >= limit && ansx < sumx) {
                ansx = sumx;
            }
            return;
        }
        bool flag = true;
        vector<int> m(materials);
        for (int i = 0; i < 5; i++) {
            if (materials[i] >= cookbooks[k][i]) {
                materials[i] -= cookbooks[k][i];
            } else flag = false;
        }

        if (flag) {
            dfs(materials, cookbooks, attribute, limit, k + 1, ansy + attribute[k][1], sumx + attribute[k][0]);
        }

        for (int i = 0; i < 5; i++) {
            if (materials[i] + cookbooks[k][i] >= cookbooks[k][i]) {
                materials[i] += cookbooks[k][i];
            }
        }
        dfs(m, cookbooks, attribute, limit, k + 1, ansy, sumx);
    }

    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit) {
        ansx = -1;
        dfs(materials, cookbooks, attribute, limit, 0, 0, 0);
        return ansx;
    }
};