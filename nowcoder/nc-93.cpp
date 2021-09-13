#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    list<pair<int,int> > cache;
    map<int,list<pair<int,int> >::iterator> ma;
    int ca;
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        ca = k;
        vector<int> ans;
        for(auto &x: operators){
            if(x[0] == 1){
                int k=x[1],v=x[2];
                set(k,v);
            }else{
                ans.push_back(get(x[1]));
            }
        }return ans;
    }
    void set(int k, int v){
        if(ma.find(k) == ma.end()){
            if(cache.size() == ca){
                ma.erase(cache.back().first);
                cache.pop_back();
            }
        }else{
            cache.erase(ma[k]);
        }
        cache.push_front(make_pair(k,v));
        ma[k]=cache.begin();
    }
    int get(int k){
        if(ma.find(k) == ma.end()) return -1;
        auto tmp = *ma[k];
        cache.erase(ma[k]);
        cache.push_front(make_pair(k, tmp.second));
        ma[k]=cache.begin();
        return tmp.second;
    }
};