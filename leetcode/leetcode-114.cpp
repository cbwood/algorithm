/*
 *@File Name          :leetcode-114.cpp
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/3/3 10:37
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "algorithm"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {

    }
};