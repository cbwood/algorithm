/*
 *@File Name          :leetcode-521.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/5 8:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "iostream"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return max(a.length(), b.length());
    }
};