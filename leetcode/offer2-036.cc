/*
 *@File Name          :offer2-036.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/2 10:24
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> sta;
        for (auto &token: tokens) {
            if (isdigit(token[token.size() - 1])) {
                sta.push(stoi(token));
            } else {
                int x = sta.top();
                sta.pop();
                int y = sta.top();
                sta.pop();
                if (token == "+")
                    sta.push(x + y);
                else if (token == "-")
                    sta.push(y - x);
                else if (token == "*")
                    sta.push(x * y);
                else if (token == "/")
                    sta.push(y / x);
            }
        }
        return sta.top();
    }
};