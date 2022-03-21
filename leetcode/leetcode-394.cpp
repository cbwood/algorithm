/*
 *@File Name          :leetcode-394.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/19 9:07
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> sta;
        int n = s.size();
        int k = 0;
        while (k < n) {
            if (s[k] != ']') {
                sta.push(string(1, s[k++]));
            } else {
                string t;
                k++;
                while (!sta.empty() && sta.top() != "[") {
                    t = sta.top() + t;
                    sta.pop();
                }
                if (!sta.empty() && sta.top() == "[") {
                    sta.pop();
                }
                int num = 0;
                int dig = 1;
                while (!sta.empty() && isdigit(sta.top()[0])) {
                    num = num + dig * stoi(sta.top());
                    dig = dig * 10;
                    sta.pop();
                }
                string tmp = t;
                for (int i = 0; i < num; i++) {
                    t += tmp;
                }
                sta.push(t);
            }
        }
        string ans;
        while (!sta.empty()) {
            ans = sta.top() + ans;
            sta.pop();
        }
        return ans;
    }
};