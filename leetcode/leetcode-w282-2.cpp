/*
 *@File Name          :leetcode-w282-2.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/27 9:46
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> ma;
        map<char, int> mb;
        for (auto &x: s)
            ma[x]++;
        for (auto &x: t)
            mb[x]++;
        int ans = s.size() + t.size();
        for (auto &x: s) {
            if (mb[x] > 0) {
                ans--;
                mb[x]--;
            }
        }
        for (auto &x: t) {
            if (ma[x] > 0) {
                ans--;
                ma[x]--;
            }
        }
        return ans;
    }
};