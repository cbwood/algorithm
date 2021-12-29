//
// Created by cb on 2021/12/28.
//

#include "algorithm"
#include "string"
#include "vector"
#include "iostream"
#include "unordered_set"
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        int n = docs.size();
        vector<string> ans;
        unordered_map<int, vector<int>> ma;
        unordered_map<int, unordered_map<int, int>> mb;
        for(int i = 0; i < n; i++){
            for(const auto &x: docs[i])
                ma[x].push_back(i);
        }

        for(auto &x: ma){
            sort(x.second.begin(),x.second.end());
            for(int i = 0; i < x.second.size(); i++){
                for(int j = i+1; j < x.second.size(); j++)
                    mb[x.second[i]][x.second[j]]++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(mb[i][j] > 0){
                    char s[100];
                    int num = docs[i].size()+docs[j].size()-mb[i][j];
                    int k = (mb[i][j]*1.0/num+0.00005)*10000;
                    sprintf(s,"%d,%d: %.4f", i, j, k*1.0/10000);
                    ans.emplace_back(s);
                }
            }
        }
        return ans;
    }
};