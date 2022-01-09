/*
 * @File Name          :leetcode-1614.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/7 9:08
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
    int maxDepth(string s) {
        int ans = 0;
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') num++;
            else if(s[i] == ')') num--;
            ans = max(ans, num);
        }return ans;
    }
};