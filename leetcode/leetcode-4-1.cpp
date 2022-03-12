/*
 *@File Name          :leetcode-4-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/12 9:44
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:

    int get(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        int idx1 = 0, idx2 = 0;
        while (true) {
            if (idx1 == n)
                return nums2[idx2 + k - 1];
            if (idx2 == m)
                return nums1[idx1 + k - 1];
            if (k == 1)
                return min(nums1[idx1], nums2[idx2]);
            int newidx1 = min(idx1 + k / 2 - 1, n - 1);
            int newidx2 = min(idx2 + k / 2 - 1, m - 1);
            if (nums1[newidx1] <= nums2[newidx2]) {
                k -= newidx1 - idx1 + 1;
                idx1 = newidx1 + 1;
            } else {
                k -= newidx2 - idx2 + 1;
                idx2 = newidx2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if ((n + m) & 1)
            return get(nums1, nums2, (n + m + 1) / 2);
        return (get(nums1, nums2, (n + m) / 2) + get(nums1, nums2, (n + m) / 2 + 1)) / 2.0;
    }
};