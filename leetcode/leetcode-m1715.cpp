//
// Created by cb on 2021/12/20.
//

#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans="";
        unordered_map<string, bool> ma;
        for(auto &x: words)
            ma[x]= true;
        for(auto &x: words){
            if(ans.size() < x.size() && check(x, 0, ma))
                ans = x;
        }return ans;
    }

    bool check(string &x, int l, unordered_map<string, bool> &ma){
        if(l >= x.size()) return true;
        string tmp="";
        for(int i = l; i <x.size(); i++){
            tmp += x[i];
            if(ma[tmp] && i-l !=x.size()-1){
                if(check(x, i+1, ma)) {
                    return true;
                }
            }
        }return false;
    }
};