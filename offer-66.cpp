#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        int suml[100001], sumr[100001];
        suml[0] = suml[n] = sumr[0] = sumr[n] = 1;
        for(int i = 0; i < n; i++)
            suml[i+1] = suml[i]*a[i];
        for(int i = n-1; i >= 0; --i)
            sumr[i] = sumr[i+1]*a[i];
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = suml[i]*sumr[i+1];
        return ans;
    }
};

int main(){
    return 0;
}