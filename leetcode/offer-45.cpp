#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &x,const string &y){
    int k = (x+y).compare(y+x);
    return k<0;
}
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> tmp;
        for(auto &x: nums)
            tmp.push_back(to_string(x));
        sort(tmp.begin(), tmp.end(), cmp);
        string ans="";
        for(auto &x: tmp)
            ans= ans + x;
        return ans;
    }
};

int main(){
    Solution so;
    vector<int> a{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout<<so.minNumber(a)<<endl;
    return 0;
}