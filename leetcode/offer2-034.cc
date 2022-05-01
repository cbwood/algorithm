/*
 *@File Name          :offer2-034.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/30 9:30
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
    bool isAlienSorted(vector<string> &words, string order) {
        vector<vector<bool>> mat(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++)
            for (int j = i; j < 26; j++)
                mat[order[i] - 'a'][order[j] - 'a'] = true;
        int len = words.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int t = min(words[i].size(), words[j].size());
                int k;
                for (k = 0; k < t; ++k) {
                    if (words[i][k] == words[j][k]) continue;
                    if (!mat[words[i][k] - 'a'][words[j][k] - 'a'])
                        return false;
                    else break;
                }
                if (k == len && words.size() > words[j].size())
                    return false;
            }
        }
        return true;
    }
};