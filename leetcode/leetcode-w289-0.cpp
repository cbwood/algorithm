/*
 *@File Name          :leetcode-w289-0.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 10:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;


class Solution {
public:
    string digitSum(string s, int k) {
        int s_size = s.size();
        while (s_size > k) {
            string t = "";
            int sumx = 0;
            for (int i = 0; i < s_size; i++) {
                if (i && i % k == 0) {
                    t += to_string(sumx);
                    sumx = 0;
                }
                sumx += s[i] - '0';
            }
            t += to_string(sumx);
            s = t;
            s_size = s.size();
        }
        return s;
    }
};