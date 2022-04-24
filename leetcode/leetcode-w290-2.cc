/*
 *@File Name          :leetcode-w290-2.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 10:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;


class Solution {
public:

    int serch(vector<vector<int>> &rectangles, int x, int idx) {
        int l = 0, r = rectangles.size() - 1;
        int ans = r + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (rectangles[mid][idx] >= x) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }

    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        int n = points.size();
        int m = rectangles.size();
        vector<vector<int>> v(101);
        for (auto &x: rectangles) {
            v[x[1]].emplace_back(x[0]);
        }
        for (int i = 0; i < 101; i++)
            std::sort(v[i].begin(), v[i].end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = points[i][1]; j < 101; j++) {
                int k = std::lower_bound(v[j].begin(), v[j].end(), points[i][0]) - v[j].begin();
                tmp += v[j].size() - k;
            }
            ans[i] = tmp;
        }
        return ans;
    }
};