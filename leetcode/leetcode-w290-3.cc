/*
 *@File Name          :leetcode-w290-3.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/24 11:50
 *@Description        :
 *@Function List      :
 *@History            :
 */
/*
 *@File Name          :fenwickTree-1D.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 8:59
 *@Description        :一维树状数组
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        vector<pair<int, int>> vec;
        for (auto &x: flowers) {
            vec.push_back({x[0], INT_MIN});
            vec.push_back({x[1], INT_MAX});
        }
        for (int i = 0; i < persons.size(); i++)
            vec.push_back({persons[i], i});
        std::sort(vec.begin(), vec.end());
        vector<int> ans(persons.size(), 0);
        int cnt = 0;
        for (auto &x: vec) {
            if (x.second == INT_MIN)
                cnt++;
            else if (x.second == INT_MAX)
                cnt--;
            else {
                ans[x.second] = cnt;
            }
        }
        return ans;
    }
};;