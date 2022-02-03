/*
 * @File Name          :leetcode-2000.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/2/2 9:14
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "algorithm"

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = -1;
        for (int i = 0; i < word.size(); i++) {
            if (ch == word[i]) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            for (int i = 0; i <= pos / 2; i++) {
                swap(word[i], word[pos - i]);
            }
        }
        return word;
    }
};