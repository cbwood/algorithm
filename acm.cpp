#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long inline df(string t) {
        long long ansx = 0;
        for (auto &x: t) {
            ansx = ansx * 10 + x - '0';
        }
        return ansx;
    }

    vector<long long> kthPalindrome(vector<int> &queries, int intLength) {
        vector<long long> ans;
        if (intLength == 1) {
            for (auto &x: queries) {
                if (x >= 1 && x <= 9) {
                    ans.push_back(x);
                } else ans.push_back(-1);
            }
            return ans;
        }
        long long base = 1;
        int k = intLength / 2 - 1;
        long long tq = 1;
        for (int i = 0; i < intLength / 2; i++)
            tq *= 10;
        if (intLength % 2) {
            tq = tq * 10;
        } else {
            tq *= 9;
        }
        while (k > 0) {
            base *= 10;
            k--;
        }
        for (auto &x: queries) {
            if (x > tq) ans.emplace_back(-1);
            else if (intLength & 1) {
                string tt = to_string(base + (x - 1) / 10);
                string ttt = tt;
                std::reverse(tt.begin(), tt.end());
                ans.emplace_back(df(ttt + string(1, (x - 1) % 10 + '0') + tt));
            } else {
                string tt = to_string(base + x - 1);
                string ttt = tt;
                std::reverse(tt.begin(), tt.end());
                ans.emplace_back(df(ttt + tt));
            }
        }
        return ans;
    }
};