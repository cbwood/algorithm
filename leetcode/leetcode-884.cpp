/*
 * @File Name          :leetcode-884.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/30 9:51
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include <sstream>
#include "map"
#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> ma;
        vector<string> ans;

        auto split = [&](const string &s) {
            stringstream ss(s);
            string w;
            while (ss >> w) {
                ++ma[move(w)];
            }
        };
        split(s1);
        split(s2);
        for (auto &x: ma) {
            if (x.second == 1)
                ans.push_back(x.first);
        }
        return ans;
    }
};