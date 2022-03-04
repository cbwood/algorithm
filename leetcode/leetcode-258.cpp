/*
 *@File Name          :leetcode-258.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/3 9:20
 *@Description        :
 *@Function List      :
 *@History            :
 */


#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};