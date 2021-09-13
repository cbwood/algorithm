/*************************************************************************
	> File Name: HDU-6377.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月13日 星期一 10时22分21秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const LL mod = 998244353;
const int maxn = 1e3 + 10;

LL dp[maxn][maxn],f[maxn];

LL qpow(LL x, LL n){
    LL ans = 1;
    x = x % mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

void init(){
    dp[1][1] = 1;
    f[0] = 1;
    LL inv = qpow(2, mod-2);
    f[1] = 2;
    for(int i = 2; i < maxn; ++i){
        for(int j = 0; j <= i; ++j){
            if(j) dp[i][j] += dp[i-1][j-1] * (2*i-j) % mod;
            dp[i][j] += dp[i-1][j] * j % mod;
            if(j+2 <= i-1) dp[i][j] += dp[i-1][j+2] * ((j+2)*(j+1)%mod *inv % mod) % mod;
            if(j+1 <= i-1) dp[i][j] += dp[i-1][j+1] * (2*i-j-2)*(j+1)%mod;
            if(i-1 >= j) dp[i][j] += dp[i-1][j] * ((2*i-j-1)*(2*i-j-2) % mod* inv % mod) % mod;
            dp[i][j] %= mod;
        }f[i] = f[i-1]*2%mod;
    }
}

int main(){
    init();
    int n,d;
    while(scanf("%d %d", &n, &d) != EOF){
        LL ans = 0;
        LL k = 1;
        for(int i = 0; i <=  n; ++i)
            (ans += dp[n][i] * k) %= mod, k=k*d%mod; 
        printf("%lld\n",ans*f[n] % mod);
    }
	return 0;
}
