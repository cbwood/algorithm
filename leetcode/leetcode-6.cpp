/*
 *@File Name          :leetcode-6.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/1 8:35
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = "";
        int step = numRows * 2 - 2;
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += step) {
                    ans += s[j];
                }
            } else {
                int st = i * 2;
                for (int j = i; j < s.size(); j += st) {
                    ans += s[j];
                    st = step - st;
                }
            }
        }
        return ans;
    }
};