/*
 *@File Name          :offer2-018.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 10:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l <= r && !isalpha(s[l]) && !isdigit(s[l])) l++;
            while (l <= r && !isalpha(s[r]) && !isdigit(s[r])) r--;
            if (l <= r && s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};