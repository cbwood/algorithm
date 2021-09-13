#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long qpow(long long n, long long k){
        long long ans = 1;
        while(k){
            if(k&1) ans *= n;
            n *= n;
            k >>= 1;
        }return ans;
    }

    long long cuttingRope(long long n) {
        long long m = 2;
        long long ans = 1;
        while(m < n){
            long long tmp = n/m;
            long long t = n%m;
            ans = max(ans, qpow(tmp, m-t)*qpow(tmp+1, t));
            m++;
        }return ans;
    }
};

int main(){
    Solution so;
    cout << so.cuttingRope(32) << endl;
    return 0;
}