/*
 *@File Name          :leetcode-93.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/26 21:18
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int cnt, int cur, string t, int pre) {
        if (cur == s.size()) {
            if (cnt == 3) {
                ans.push_back(t);
            }
            return;
        }
        if (cnt > 3) return;
        if (pre == 0) {
            dfs(s, cnt + 1, cur + 1, t + "." + s[cur], s[cur] - '0');
        } else {
            if (pre == -1) {
                dfs(s, cnt, cur + 1, t + s[cur], s[cur] - '0');
            } else {
                dfs(s, cnt + 1, cur + 1, t + "." + s[cur], s[cur] - '0');
                if (pre * 10 + s[cur] - '0' <= 255)
                    dfs(s, cnt, cur + 1, t + s[cur], pre * 10 + s[cur] - '0');
            }

        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "", -1);
        return ans;
    }
};
