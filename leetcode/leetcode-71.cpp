/*
 * @File Name          :leetcode-71.cpp
 * @Author             :cc
 * @Version            :1.0.0
 * @Date               :2022/1/6 9:11
 * @Description        :
 * @Function List      :
 * @History            :
 */

#include "string"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string pat="";
        vector<string> tmp;
        path += "/";
        for(int i = 0; i < path.size(); i++){
            if(path[i] != '/')
                pat += path[i];
            else {
                if(!pat.empty())
                    tmp.push_back(pat);
                pat="";
            }
        }

        string ans="";
        string cur=".";
        string pred="..";
        vector<string> vec;
        for(auto &x: tmp){
            if(x == pred && !vec.empty())
                vec.pop_back();
            else if(x != pred && x != cur)
                vec.push_back(x);
        }
        for(auto &x: vec)
            ans += "/"+x;
        if(ans.empty()) ans="/";
        return ans;
    }
};