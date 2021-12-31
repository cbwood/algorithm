/*
 * @File Name          :leetcode-507.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2021/12/31 9:02
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sumx = 1;
        if(num == 1) return false;
        int k = sqrt(num);
        for(int i = 2; i <= k; i++){
            if(num%i == 0)
            sumx += i + num/i;
        }return sumx == num;
    }
};