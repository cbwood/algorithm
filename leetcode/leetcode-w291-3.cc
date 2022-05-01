/*
 *@File Name          :leetcode-w291-3.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/1 10:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        vector<int> cnt(30, -1);
        long long ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            long long tmp = n - i;
            if (cnt[s[i] - 'a'] != -1)
                tmp += 1LL * (i - cnt[s[i] - 'a'] - 1) * (n - i);
            else tmp += 1LL * i * (n - i);
            ans += tmp;
            cnt[s[i] - 'a'] = i;
        }
        return ans;
    }
};