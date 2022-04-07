/*
 *@File Name          :heapSort.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/7 9:28
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

void sift_down(vector<int> &nums, int start, int end) {
    int p = start;
    int ch = p * 2 + 1;
    while (ch <= end) {
        if (ch + 1 <= end && nums[ch + 1] > nums[ch]) ch++;
        if (nums[p] >= nums[ch]) return;
        swap(nums[p], nums[ch]);
        p = ch;
        ch = p * 2 + 1;
    }
}

vector<int> sortArray(vector<int> &nums) {
    int n = nums.size() - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        sift_down(nums, i, n);
    for (int i = n; i > 0; --i) {
        swap(nums[0], nums[i]);
        sift_down(nums, 0, i - 1);
    }
    return nums;
}