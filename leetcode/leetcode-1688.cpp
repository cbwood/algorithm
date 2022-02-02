/*
 * @File Name          :leetcode-1688.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/25 9:48
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            ans += n / 2;
            n = (n + 1) / 2;
        }
        return ans;
    }
};