//
// Created by cb on 2021/9/24.
//

#include "vector"
#include "map"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r] == target){
                ans.emplace_back(vector<int>{nums[l], nums[r]});
                l++;
                r--;
            }else if(nums[l]+nums[r] > target)
                r--;
            else l++;
        }
        return ans;
    }
};