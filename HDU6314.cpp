/*************************************************************************
	> File Name: HDU6314.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月27日 星期五 14时04分37秒
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
const int mod = 998244353;
const int maxn = 3e3 + 1;

LL fi[maxn], ni[maxn];
int q[maxn*maxn];
int f[maxn][maxn];
int c[maxn][maxn];

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

void init(){
    fi[1] = ni[1] = q[0] = 1;
    for(int i = 2; i < maxn; ++i){
        fi[i] = fi[i-1] * i% mod;
        ni[i] = qpow(fi[i], mod-2);
    }for(int i = 0; i < maxn; ++i){
        c[i][0] = c[i][i] = 1;
    }for(int i = 2; i < maxn; ++i)
        for(int j = 1; j < i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    for(int j = 2; j < maxn; ++j)
        for(int i = j-1; i >= 1; --i)
            f[i][j] = (f[i+1][j] + c[j][i]) % mod;
    for(int i = 1; i < maxn*maxn; ++i)
        q[i] = q[i-1] * 2 % mod;
}


int main(){
    int n, m, a, b;
    init();
    while(scanf("%d %d %d %d",&n, &m, &a, &b) != EOF){
        LL ans = 0, tmp;
        for(int i= a; i<= n; ++i){
            tmp = ((1-f[a][i]) +mod)%mod*c[n][i]%mod;
            for(int j = b; j <= m; ++j){
                ans = (ans + tmp * ((1-f[b][j])+mod)%mod*c[m][j]%mod * q[(n-i)*(m-j)])%mod;
            }
        }printf("%lld\n", ans);
    }return 0;
}
