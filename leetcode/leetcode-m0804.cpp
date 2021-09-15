//
// Created by cb on 2021/9/15.
//

#include "vector"
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        dfs(nums, 0, t);
        return ans;
    }

    void dfs(vector<int> &num, int k, vector<int> &t){
        if(k == num.size()){
            ans.push_back(t);
            return;
        }
        dfs(num, k+1, t);
        t.push_back(num[k]);
        dfs(num, k+1,t);
        t.pop_back();
    }

private:
    vector<vector<int>> ans;
};