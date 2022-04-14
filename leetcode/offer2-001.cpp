/*
 *@File Name          :offer2-001.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 19:57
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == 0) return 0;
        if (b == 1) return a;
        if (b == -1 && a != INT_MIN) return -a;
        if (b == INT_MIN)
            return a == INT_MIN ? 1 : 0;
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        int ans = 0;
        int flag = (a > 0) ^ (b > 0);
        b = abs(b);

        if (a == INT_MIN) {
            a -= -b;
            ++ans;
        }
        a = abs(a);

        for (int i = 31; i >= 0; --i) {
            if ((a >> i) >= b) {
                a -= (b << i);
                if (ans > INT_MAX - (1 << i))
                    return INT_MIN;
                ans += (1 << i);
            }
        }
        return flag == 0 ? ans : -ans;
    }
};