//
// Created by cb on 2021/9/24.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"
using namespace std;


class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        unordered_map<string, int> ma;
        unordered_map<string, string> mb;
        for(auto &x: names) {
            size_t pos = x.find('(');
            ma[x.substr(0, pos)] = std::stoi(x.substr(pos+1,x.size()-pos-2));
        }
        for(auto &x: synonyms){
            size_t pos = x.find(',');
            string n1 = x.substr(1, pos-1);
            string n2 = x.substr(pos+1, x.size()-pos-2);
            if(n1 > n2){
                swap(n1, n2);
            }
            string t1 = n1, t2 = n2;
            while(!mb[n2].empty()){
                n2 = mb[n2];
            }
            while(!mb[n1].empty()){
                n1 = mb[n1];
            }
            if(t1 != n1)
                mb[t1] = n1;
            if(t2 != n2)
                mb[t2] = n2;
            if(n1 <= n2){
                mb[n2] = n1;
                ma[n1] += ma[n2];
                ma.erase(n2);
            }else {
                ma[n2] += ma[n1];
                ma.erase(n1);
                mb[n1] = n2;
            }
        }
        vector<string> ans;
        for(auto &x: ma){
            string tmp = x.first+"(" +to_string(x.second)+")";
            ans.push_back(tmp);
        }
        return ans;

    }
};