/*
 * @File Name          :leetcode-2047.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/27 9:53
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include "string"

using namespace std;

class Solution {
public:
    int countValidWords(string sentence) {
        int ans = 0;
        bool check = true;
        int num = 0;
        int num_ = 0;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (check && num && num_ < 2) ans++;
                num = 0;
                num_ = 0;
                check = true;
            } else if (sentence[i] >= '0' && sentence[i] <= '9') {
                check = false;
            } else if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                num++;
            } else if (sentence[i] == '-') {
                if ((i > 0 && sentence[i - 1] >= 'a' && sentence[i - 1] <= 'z') && i < sentence.size() - 1 &&
                    sentence[i + 1] >= 'a' && sentence[i + 1] <= 'z')
                    num++;
                else check = false;
                num_++;
            } else {
                if (i == sentence.size() - 1 || sentence[i + 1] == ' ') {
                    num++;
                } else check = false;
            }
        }
        if (check && num) ans++;
        return ans;
    }
};