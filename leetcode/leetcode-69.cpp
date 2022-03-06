/*
 *@File Name          :leetcode-69.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/6 9:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            long long sm = (long long) mid * mid;
            if (sm > x)
                r = mid - 1;
            else if (sm == x) return mid;
            else l = mid + 1;
        }
        if ((long long) l * l > x) l--;
        return l;
    }
};