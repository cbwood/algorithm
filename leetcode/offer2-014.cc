/*
 *@File Name          :offer2-014.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/20 9:50
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> count_char;
        for (const char &ch: s1) {
            count_char[ch]++;
        }

        int l = 0, r = 0, len_s1 = s1.size();
        int num = 0, len_s2 = s2.size();
        while (r < len_s2) {
            if (count_char.find(s2[r]) == count_char.end()) {
                while (l < r) {
                    count_char[s2[l]]++;
                    l++;
                }
                r++;
                l = r;
                num = 0;
                continue;
            }
            count_char[s2[r]]--;

            num++;
            while (count_char[s2[l]] < 0 || num > len_s1 || count_char[s2[r]] < 0) {
                count_char[s2[l]]++;
                l++;
                num--;
            }
            r++;
            if (num == len_s1) {
                return true;
            }
        }
        return false;
    }
};