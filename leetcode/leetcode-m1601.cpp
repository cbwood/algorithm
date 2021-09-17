//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "algorithm"
#include "string"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0]^numbers[1];//numbers[0]&numbers[1]
        numbers[1] = numbers[0]^numbers[1];//numbers[0]
        numbers[0] = numbers[0]^numbers[1];
        return numbers;
    }
};