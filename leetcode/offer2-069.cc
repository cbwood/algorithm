/*
 *@File Name          :offer2-069.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/5/27 9:05
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int lmid = l + (r - l) / 3;
            int rmid = r - (r - l) / 3;
            if (arr[lmid] < arr[rmid])
                l = lmid + 1;
            else r = rmid - 1;
        }
        return l;
    }
};