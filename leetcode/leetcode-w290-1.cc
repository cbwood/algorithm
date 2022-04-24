/*
 *@File Name          :leetcode-w290-1.cc
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

    int dis(int x, int y, int xx, int yy) {
        return (x - xx) * (x - xx) + (y - yy) * (y - yy);
    }

    int countLatticePoints(vector<vector<int>> &circles) {
        int ans = 0;
        for (int i = -102; i <= 202; i++) {
            for (int j = -102; j <= 202; j++) {
                for (auto &x: circles) {
                    if (x[2] * x[2] >= dis(i, j, x[0], x[1])) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

/*
 * 28443
 */