/*
 *@File Name          :leetcode-819.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/17 9:59
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "map"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        map<string, bool> is_banned;
        is_banned[""] = true;
        for (auto &x: banned)
            is_banned[x] = true;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        map<string, int> ans;
        int prei = 0;
        for (int i = 0; i < paragraph.size(); i++) {
            if (!isalpha(paragraph[i])) {
                string tmp = paragraph.substr(prei, i - prei);
                if (!is_banned[tmp])
                    ans[tmp]++;
                prei = i + 1;
            }
        }
        string tmp = paragraph.substr(prei, paragraph.size() - prei);
        if (!is_banned[tmp])
            ans[tmp]++;
        int max_num = INT_MIN;
        string t;
        for (auto &x: ans) {
            if (x.second > max_num) {
                max_num = x.second;
                t = x.first;
            }
        }
        return t;
    }
};