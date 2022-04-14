/*
 *@File Name          :offer2-005.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/13 21:20
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
    int maxProduct(vector<string> &words) {
        int len_words = words.size();
        vector<int> dp(len_words, 0);
        for (int i = 0; i < len_words; ++i) {
            for (const auto &w: words[i]) {
                dp[i] |= (1 << (w - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < len_words; ++i)
            for (int j = i + 1; j < len_words; ++j) {
                if ((dp[i] & dp[j]) == 0 && ans < words[i].length() * words[j].length()) {
                    ans = words[i].length() * words[j].length();
                }
            }
        return ans;
    }
};