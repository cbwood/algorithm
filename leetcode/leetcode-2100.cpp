/*
 *@File Name          :leetcode-2100.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/6 8:53
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
    vector<int> goodDaysToRobBank(vector<int> &security, int time) {
        int n = security.size();
        vector<int> prenum(n, 0);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1])
                prenum[i] = prenum[i - 1] + 1;
        }
        vector<int> ans;
        int postnum = 0;
        if (postnum >= time) ans.emplace_back(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1])
                postnum = postnum + 1;
            else postnum = 0;
            if (postnum >= time && prenum[i] >= time) ans.emplace_back(i);
        }
        return ans;
    }
};