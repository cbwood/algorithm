/*
 *@File Name          :leetcode-m0402-1.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/2 10:47
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "vector"
#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode *build(int l, int r, const vector<int> &nums) {
        if (r < l) return nullptr;
        int mid = (r + l) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = build(l, mid - 1, nums);
        cur->right = build(mid + 1, r, nums);
        return cur;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int n = nums.size() - 1;
        return build(0, n, nums);
    }
};