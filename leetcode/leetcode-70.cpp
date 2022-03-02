/*
 *@File Name          :leetcode-70.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/2 10:59
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int ans = 0;
        int a = 1;
        int b = 2;
        if (n == 1) return 1;
        if (n == 2) return 2;
        while (2 < n) {
            n--;
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};