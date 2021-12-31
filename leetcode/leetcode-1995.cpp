//
// Created by cb on 2021/12/29.
//


#include "vector"
#include "algorithm"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        vector<int> vec(301,0);
        int ans = 0;
        for(int i = 1; i < nums.size()-2; i++) {
            for (int j = i - 1; j >= 0; j--) {
                vec[nums[j] + nums[i]+100]++;
            }
            for(int j = i+2; j < nums.size(); j++)
                ans += vec[nums[j]-nums[i+1]+100];
        }
        return ans;
    }
};