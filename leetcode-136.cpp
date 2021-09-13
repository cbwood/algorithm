#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(const auto &x : nums)
            ans ^= x;
        return  ans;
    }
};

int main(){
    Solution s;
    vector<int> a;
    int n;
    while(cin >> n){
        while(n--){
            int x;
            cin >> x;
            a.push_back(x);
        }
        cout << s.singleNumber(a) << endl;
    }
    return 0;
}
