//
// Created by cb on 2021/9/23.
//

#include "algorithm"
#include "climits"
#include "vector"
#include "map"
#include "string"
using namespace std;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> mat{"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        map<char, char> ma;
        for(int i = 2; i <= 9; i++){
            for(int j = 0; j < mat[i].length(); j++)
                ma[mat[i][j]]=i+'0';
        }
        vector<string> ans;
        for(auto &x: words){
            bool check = true;
            for(int i = 0; i < x.length(); i++){
                if(ma[x[i]] != num[i]){
                    check = false;
                    break;
                }
            }if(check) ans.push_back(x);
        }return ans;
    }
};