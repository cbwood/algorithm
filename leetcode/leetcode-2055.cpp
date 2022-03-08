/*
 *@File Name          :leetcode-2055.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/8 8:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
        vector<int> preSum(s.size(), 0);
        bool check = s[0] == '|' ? true : false;
        int prex = s[0] == '|' ? 0 : 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '|') {
                if (check) {
                    preSum[i] = preSum[i - 1] + prex;
                } else preSum[i] = preSum[i - 1];
                prex = 0;
                check = true;
            } else {
                preSum[i] = preSum[i - 1];
                prex++;
            }
        }
        vector<int> r(s.size(), s.size());
        int rx = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '|') rx = i;
            r[i] = rx;
        }
        vector<int> ans;
        for (auto &x: queries) {
            ans.emplace_back(max(0, preSum[x[1]] - preSum[r[x[0]]]));
        }
        return ans;
    }
};