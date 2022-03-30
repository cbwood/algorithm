/*
 *@File Name          :leetcode-2024.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/29 8:53
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int num = 0;
        int ans = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (answerKey[r] == 'T')
                num++;
            r++;
            while (num > k) {
                if (answerKey[l] == 'T')
                    num--;
                l++;
            }
            ans = max(r - l, ans);
        }
        num = 0;
        l = 0, r = 0;
        while (r < n) {
            if (answerKey[r] == 'F')
                num++;
            r++;
            while (num > k) {
                if (answerKey[l] == 'F')
                    num--;
                l++;
            }
            ans = max(r - l, ans);
        }
        return ans;
    }
};