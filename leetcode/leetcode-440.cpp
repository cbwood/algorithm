/*
 *@File Name          :leetcode-440.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/23 10:07
 *@Description        :给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1;
        auto getCount = [&](int cur) {
            int num = 0;
            long long f = cur;
            long long l = cur;
            while (f <= n) {
                num += min(l, 1LL * n) - f + 1;
                f = f * 10;
                l = l * 10 + 9;
            }
            return num;
        };
        k--;
        while (k) {
            int t = getCount(ans);
            if (t <= k) {
                k -= t;
                ans++;
            } else {
                k--;
                ans *= 10;
            }
        }
        return ans;
    }
};