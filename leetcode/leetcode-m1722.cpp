//
// Created by cb on 2021/12/24.
//

#include "algorithm"
#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    vector<bool> vis;
    vector<string> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<string> ans;
        vis = vector<bool>(wordList.size(), false);
        dfs(ans, beginWord, endWord, wordList);
        return ans;
    }

    bool check(string x, string y){
        if(x.size() != y.size()) return false;
        int num = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] != y[i]) num++;
        }
        return num == 1;
    }

    bool dfs(vector<string> &ans, string tmpWord, string endWord,vector<string> &wordList) {
        ans.push_back(tmpWord);
        if (tmpWord == endWord) {
            return true;
        }
        for(int i = 0; i < wordList.size(); i++){
            if(!vis[i] && check(tmpWord, wordList[i])){
                vis[i] = true;
                if(dfs(ans, wordList[i], endWord, wordList)) return true;
                vis[i] = false;
            }
        }
        ans.pop_back();
        return false;
    }
};
