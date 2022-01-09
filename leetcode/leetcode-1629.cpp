/*
 * @File Name          :leetcode-1629.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/9 15:32
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "string"
#include "algorithm"
using namespace std;


class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans;
        int num = 0;
        int pre = 0;
        for(int i = 0; i < releaseTimes.size(); i++){
            int t = releaseTimes[i] - pre;
            pre = releaseTimes[i];
            if(t >= num){
                if(t > num){
                    ans = keysPressed[i];
                }else if(ans < keysPressed[i])
                    ans = keysPressed[i];
                num = t;
            }
        }return ans;
    }
};