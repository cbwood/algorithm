/*
 *@File Name          :leetcode-2104.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/4 9:06
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"
#include "stack"

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> lmin(n, 0), lmax(n, n - 1);
        stack<int> minStack, maxStack;
        for (int i = 0; i < n; i++) {
            while (!minStack.empty() && nums[minStack.top()] > nums[i])
                minStack.pop();
            lmin[i] = minStack.empty() ? -1 : minStack.top();
            minStack.emplace(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i])
                maxStack.pop();
            lmax[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.emplace(i);
        }

        while (!minStack.empty()) minStack.pop();
        while (!maxStack.empty()) maxStack.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i])
                minStack.pop();
            int minr = minStack.empty() ? n : minStack.top();
            minStack.emplace(i);
            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i])
                maxStack.pop();
            int maxr = maxStack.empty() ? n : maxStack.top();
            maxStack.emplace(i);
            ans = ans + (long long) ((maxr - i) * (i - lmax[i]) - (minr - i) * (i - lmin[i])) * nums[i];
        }
        return ans;
    }
};

///*
// *@File Name          :leetcode-2104.cpp
// *@Author             :cc
// *@Version            :1.0.0
// *@Date               :2022/3/4 9:06
// *@Description        :
// *@Function List      :
// *@History            :
// */
//
//#include "vector"
//#include "algorithm"
//using namespace std;
//
//class Solution {
//public:
//    long long subArrayRanges(vector<int>& nums) {
//        long long ans = 0;
//        for(int i = 0; i < nums.size(); i++){
//            int minx = nums[i], maxx = nums[i];
//            for(int j = i+1; j < nums.size(); j++){
//                minx = min(minx, nums[j]);
//                maxx = max(maxx, nums[j]);
//                ans += maxx-minx;
//            }
//        }return ans;
//    }
//};