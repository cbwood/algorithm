//
// Created by cb on 2021/9/16.
//

#include "vector"
#include "string"
#include "map"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> tmp;
        map<string ,int> ma;
        for(auto &str: strs){
            string t = str;
            sort(t.begin(), t.end());
            if(ma.count(t) == 0){
                ans.push_back(vector<string>);
                ma[t] = ans.size()-1;
            }ans[ma[t]].push_back(str);
        }return ans;
    }
};