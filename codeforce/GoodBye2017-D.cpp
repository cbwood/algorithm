/*************************************************************************
	> File Name: GoodBye2017-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月01日 星期一 14时27分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e3+ 10;

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans =ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

LL inv(LL x){
    return qpow(x, mod-2);
}

LL dp[maxn][maxn];

int main(){
    LL k, pa, pb;
    cin >> k >> pa >> pb;
    LL t = pa + pb;
    pa = pa * inv(t) % mod;
    pb = pb * inv(t) % mod;
    LL p = pa * inv(pb) % mod;
    for(int i = k; i >= 0; --i)
        for(int j = k; j >= 0; --j){
            if(i + j >= k) dp[i][j] = (i + j + p) % mod;
            else dp[i][j] = ( dp[i+1][j] * pa % mod + dp[i][i+j] * pb % mod) % mod;
        }
    cout << dp[1][0] << endl;
	return 0;
}
