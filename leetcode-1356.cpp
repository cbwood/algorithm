#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> a;
        for(auto &x: arr){
            int t =  0;
            int k = x;
            while(k){
                if(k&1) t++;
                k /=2;
            }pair<int, int> tmp(t, x);
            a.push_back(tmp); 
        }sort(a.begin(), a.end());
        vector<int> ans;
        for(auto &x: a)
            ans.push_back(x.second);
        return ans;
    }
};

int main(){
    Solution so;
    vector<int> arr{0,1,2,3,4,5,6,7,8};
    vector<int> ans = so.sortByBits(arr);
    for(auto &x: ans)
        cout << x << " ";
    cout << endl;
    return 0;
}