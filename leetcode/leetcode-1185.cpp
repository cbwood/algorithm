/*
 * @File Name          :leetcode-1185.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/3 13:34
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> ans{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int mon[]= {0,31, 28, 31, 30, 31, 30, 31, 31, 30,31, 30, 31};
        int k = day;
        if((year%4==0&&year%100!=0)||year%400==0)
            mon[2] = 29;
        for(int i = 1; i < month; i++){
            k += mon[i];
        }
        while(year > 1971){
            year--;
            if((year%4==0&&year%100!=0)||year%400==0)
                k += 366;
            else k += 365;
        }k %= 7;
        k = (k+4)%7;
        return ans[k];
    }
};