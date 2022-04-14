/*
 *@File Name          :offer2-003.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 20:41
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> ans = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i / 2] + (i & 1);
        return ans;
    }
};