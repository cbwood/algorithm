/*
 * @File Name          :leetcode-912.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/5 9:22
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
#include "ctime"
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        int k = rand()%(r-l+1)+l;
        swap(nums[k], nums[l]);
        int i = l, j = r;
        while(i < j){
            while(i < j && nums[j] >= nums[l]) j--;
            while(i < j && nums[i] <= nums[l]) i++;
            if(i < j) swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        quickSort(nums,l, i-1);
        quickSort(nums,i+1, r);
    }
};