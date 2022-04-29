/*
 *@File Name          :offer2-032.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/29 9:29
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s == t) return false;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        if (s == t) return true;
        return false;
    }
};