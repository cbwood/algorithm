/*
 * @File Name          :leetcode-88.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/24 15:00
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        m--;
        n--;
        int k = m + n + 1;
        while (m >= 0 && n >= 0) {
            if (nums1[m] <= nums2[n]) {
                nums1[k--] = nums2[n--];
            } else {
                nums1[k--] = nums1[m--];
            }
        }
        while (m >= 0) nums1[k--] = nums1[m--];
        while (n >= 0) nums1[k--] = nums2[n--];
    }
};