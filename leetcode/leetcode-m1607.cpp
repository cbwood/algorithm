//
// Created by cb on 2021/9/18.
//

class Solution {
public:
    int maximum(int a, int b) {
        return (a+b+abs(a-b))/2;
    }
};