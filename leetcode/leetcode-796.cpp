/*
 *@File Name          :leetcode-796.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 8:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = goal.size();
        s = s + s;
        if (s.size() != n * 2)
            return false;
        for (int i = 0; i < n; i++) {
            if (s.substr(i, n) == goal)
                return true;
        }
        return false;
    }
};