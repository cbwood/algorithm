/*
 *@File Name          :leetcode-693.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/28 8:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = -1;
        while (n) {
            if (k == -1) {
                k = n % 2;
            } else {
                if (n % 2 == 1 - k) {
                    k = 1 - k;
                } else return false;
            }
            n /= 2;
        }
        return true;
    }
};