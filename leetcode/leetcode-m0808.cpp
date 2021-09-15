//
// Created by cb on 2021/9/15.
//

#include "string"
#include "vector"
#include "map"
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
        map<char, bool> ma;
        for(int i = 0; i < S.length(); i++){
            if(!vis[i] && !ma[S[i]]){
                vis[i] = true;
                ma[S[i]] = true;
                dfs(S, t+S[i], k+1, vis);
                vis[i] = false;
            }
        }
    }

private:
    vector<string> ans;
};