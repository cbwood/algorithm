//
// Created by cb on 2021/9/15.
//

#include "iostream"
#include "cmath"
#include "vector"
using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        vector<int> f(n+5, 0);
        f[1] = 1;
        f[2] = 2;
        f[3] = 4;
        for(int i = 4; i <= n; i++)
            f[i] = ((f[i-1]+f[i-2])%mod+f[i-3])%mod;
        return f[n];
    }

private:
    const int mod = 1e9+7;
};

int main(){
    return 0;
}