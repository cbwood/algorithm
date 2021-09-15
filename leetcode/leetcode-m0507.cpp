//
// Created by cb on 2021/9/15.
//

#include "iostream"
using namespace std;

class Solution {
public:
    int exchangeBits(int num) {
        return ((num&0x55555555)<<1)|((num&0xaaaaaaaa)>>1);
    }
};

int main(){
    Solution so;
    cout<<so.exchangeBits(3);
    return 0;
}