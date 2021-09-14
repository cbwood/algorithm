//
// Created by cb on 2021/9/13.
//

#include "vector"
using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        gp = vector<vector<int>>(n);
        for(vector<int> &x: graph){
            gp[x[0]].push_back(x[1]);
        }
        return dfs(n, start, target);
    }

    bool dfs(int n, int start, int target){
        if(start == target) return true;
        vis[start] = true;
        for(auto &x : gp[start]){
            if(!vis[x]){
                if(dfs(n, x, target)) return true;
            }
        }return false;
    }

private:
    vector<bool> vis= vector<bool>(1e5+1,0);
    vector<vector<int>> gp;
};