//
// Created by cb on 2021/9/24.
//

#include "algorithm"

class Solution {
public:
    int add(int a, int b) {
        while((a&b) != 0){
            int tmp = a;
            a = (unsigned int)(a&b)<<1;
            b = tmp^b;
        }return a^b;
    }
};