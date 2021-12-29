//
// Created by cb on 2021/11/1.
//
#include "vector"
#include "algorithm"
#include "climits"

using namespace std;

class Solution {
public:
    static bool cmp(const pair<int, int> &p, const pair<int, int> &q){
        if(p.first != q.first) return (p.first < q.first);
        return (p.second>q.second);
    }
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>> person;
        for(int i = 0; i < height.size(); i++)
            person.emplace_back(make_pair(height[i], weight[i]));
        sort(person.begin(), person.end(), cmp);
        vector<int> dp;
        int ans = 1;
        for(int i = 0; i < weight.size(); i++){
            auto p = lower_bound(dp.begin(), dp.end(), person[i].second);
            if(p == dp.end()) dp.push_back(person[i].second);
            else *p = person[i].second;
        }return dp.size();
    }
};