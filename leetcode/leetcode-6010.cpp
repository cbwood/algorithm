/*
 *@File Name          :leetcode-6010.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/27 10:36
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    long long check(long long y, vector<int> &time, int totalTrips) {
        long long ans = 0;
        for (auto &x: time) {
            ans += y / x;
            if (ans >= totalTrips) break;
        }
        return ans;
    }

    long long minimumTime(vector<int> &time, int totalTrips) {
        int maxn = 1e7;
        int numx = 0;
        sort(time.begin(), time.end());
        long long l = 1, r = 1e18, ans = 1;
        while (r >= l) {
            long long mid = l + (r - l) / 2;
            if (check(mid, time, totalTrips) >= totalTrips) {
                r = mid - 1;
                ans = mid;
            } else l = mid + 1;
        }
        return ans;
    }
};