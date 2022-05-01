/*
 *@File Name          :leetcode-w291-1.cc
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
    static const int maxn = 1e6 + 10;

    int minimumCardPickup(vector<int> &cards) {
        int ans = -1;
        int n = cards.size();
        int l = 0, r = 0;
        vector<int> nums(maxn, 0);
        while (r < n) {
            nums[cards[r]]++;
            while (nums[cards[r]] > 1) {
                if (ans == -1) ans = r - l + 1;
                ans = min(ans, r - l + 1);
                nums[cards[l]]--;
                l++;

            }
            r++;
        }
        return ans;
    }
};