/*
 * @File Name          :leetcode-2022.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/1 11:21
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n,0));
        int k = original.size();
        for(int i = 0; i < k; i++){
            ans[i/n][i%n] = original[i];
        }return ans;
    }
};