/*
 *@File Name          :leetcode-537.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/2/25 8:48
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"
#include "vector"
#include "string"
#include "iostream"
#include "sstream"

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        vector<int> a, b;
        auto parse = [](string &s) {
            stringstream ss(s);
            int x, y;
            char add;
            ss >> x >> add >> y;
            vector<int> t;
            t.push_back(x);
            t.push_back(y);
            return t;
        };
        a = parse(num1);
        b = parse(num2);
        int x = a[0] * b[0] - a[1] * b[1];
        int y = a[0] * b[1] + a[1] * b[0];
        string ans = to_string(x) + "+" + to_string(y) + "i";
        return ans;
    }
};