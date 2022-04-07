/*
 *@File Name          :leetcode-420.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 8:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool check(const string &t) {
        int numa1 = 0, numa2 = 0, numd = 0;
        int num = 0;
        int n = t.size();
        for (int i = 0; i < n; i++) {
            if (islower(t[i])) numa2++;
            if (isupper(t[i])) numa1++;
            if (isdigit(t[i])) numd++;
            if (i == 0 || t[i] == t[i - 1])
                num++;
            else {
                num = 1;
            }
            if (num > 3)
                return false;
        }
        return true;
    }


    int strongPasswordChecker(string password) {
        int n = password.size();
        int numUpper = 0, numLower = 0, numDigit = 0;
        for (auto &x: password) {
            if (isupper(x)) numUpper = 1;
            if (islower(x)) numLower = 1;
            if (isdigit(x)) numDigit = 1;
        }
        int ans = numUpper + numLower + numDigit;

        int numDelete = 0;
        int numEdit = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (isalpha(password[i]) && (i == 0 || password[i] == password[i - 1]))
                num++;
            else {
                numEdit += num / 3;
                if (isalpha(password[i]))
                    num = 1;
                else num = 0;
            }
        }
        numEdit += num / 3;
//todo 学习大模拟
        if (n < 6) {
            return max(6 - n, ans);
        } else if (n > 20) {
            int k = n - 20;
            for (int i = 0; i < n; i++) {
                if (isalpha(password[i]) && (i == 0 || password[i] == password[i - 1]))
                    num++;
                else {
                    numEdit += num / 3;
                    if (isalpha(password[i]))
                        num = 1;
                    else num = 0;
                }
            }
        }
    }
};