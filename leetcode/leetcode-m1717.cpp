//
// Created by cb on 2021/12/20.
//

#include "algorithm"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> ans;
        for(auto &x: smalls){
            int npos = 0;
            vector<int> tmp;
            while(!x.empty()&&(npos=big.find(x, npos))!=string::npos){
                tmp.push_back(npos++);
            }ans.push_back(tmp);
        }return ans;
    }
};