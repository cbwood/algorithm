#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dis(int a, int b){
        return a*a+b*b;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int> > p;
        int n = points.size();
        for(int i = 0; i < n; ++i){
            int d = dis(points[i][0], points[i][1]);
            p.push_back(make_pair(d, i));
        }sort(p.begin(), p.end());
        vector<vector<int>> ans;
        for(int i = 0; i < K; ++i){
            vector<int> q{points[p[i].second][0], points[p[i].second][1]};
            ans.push_back(q);
        }return ans;
    } 
};

