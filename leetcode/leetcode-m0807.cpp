//
// Created by cb on 2021/9/15.
//

#include "string"
#include "vector"
using namespace std;

class Solution {
public:
    vector<string> permutation(string S) {
        vector<bool> vis(S.length(), false);
        dfs(S, "", 0, vis);
        return ans;
    }

    void dfs(string &S, string t, int k, vector<bool> &vis){
        if(t.length() == S.length()){
            ans.push_back(t);
            return;
        }
        for(int i = 0; i < S.length(); i++){
            if(!vis[i]){
                vis[i] = true;
                dfs(S, t+S[i], k+1, vis);
                vis[i] = false;
            }
        }
    }

private:
    vector<string> ans;

};