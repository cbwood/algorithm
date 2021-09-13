#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long qpow(long long x, long long n, long long mod){
        long long ans = 1;
        x %= mod;
        while(n){
            if(n&1) ans = ans * x % mod;
            n >>= 1;
            x = x * x % mod;
        }return ans;
    }

    long long cuttingRope(long long n) {
        long long mod = 1e9+7;
        long long ans = 1;
        if(n%3 == 1){
            ans = min(n, 4LL);
            n -= 4;
        }
        ans = ans * qpow(3, n/3, mod);
        if(n%3) ans = ans*(n%3)%mod;
        if(n == 2) ans = 1;
        if(n == 3) ans = 2;
        return ans;
    }
};

int main(){

    return 0;
}