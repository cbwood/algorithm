//
// Created by cb on 2021/9/17.
//

#include "vector"
#include "algorithm"
#include "iostream"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i+=2){
            int k = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = k;
        }
    }
};

int main() {
    Solution so;
    vector<int> a{3,5,2,1,6,4};
    so.wiggleSort(a);
    return 0;
}