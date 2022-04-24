/*
 *@File Name          :offer2-019.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 10:18
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        int num = 0;
        while (l <= r) {
            if (s[l] != s[r]) {
                num++;
                if (num == 2) break;
                l++;
                continue;
            }
            l++;
            r--;
        }
        if (num <= 1) return true;

        l = 0, r = s.size() - 1;
        num = 0;
        while (l <= r) {
            if (s[l] != s[r]) {
                num++;
                if (num == 2) break;
                r--;
                continue;
            }
            l++;
            r--;
        }
        if (num <= 1) return true;
        return false;
    }
};