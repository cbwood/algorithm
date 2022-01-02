/*
 * @File Name          :leetcode-390.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/2 14:19
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "algorithm"
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int ans = 1;
        int k = 0;
        int d = 1;
        while(n>1){
            if(k&1){
                if(n&1)
                    ans += d;
            }else ans += d;
            d <<= 1;
            k++;
            n >>= 1;
        }return ans;
    }
};

/*
 * 1 1
 * 1 2 2
 * 1 2 3 2
 * 1 2 3 4 2
 * 1 2 3 4 5 2
 * 1 2 3 4 5 6 4
 * 1 2 3 4 5 6 7 4
 * 1 2 3 4 5 6 7 8 6
 * 1 2 3 4 5 6 7 8 9 6
 * 1 2 3 4 5 6 7 8 9 10 8
 * 1 2 3 4 5 6 7 8 9 10 11 6
 */