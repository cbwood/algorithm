/*
 * @File Name          :leetcode-1332.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/22 10:09
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return 2;
        }
        return 1;
    }
};