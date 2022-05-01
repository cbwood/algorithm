/*
 *@File Name          :leetcode-w291-2.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/1 10:22
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countDistinct(vector<int> &nums, int k, int p) {
        int ans = 0;
        set<string> se;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            string tmp = "";
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k) {
                    tmp = tmp + to_string(nums[j]) + "-";
                    se.insert(tmp);
                } else break;
            }
        }
        return se.size();
    }
};