//
// Created by cb on 2021/9/15.
//

#include "vector"
using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == i)
                return i;
        return -1;
    }
};