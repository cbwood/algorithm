/*************************************************************************
	> File Name: HDU6327.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月31日 星期二 09时49分03秒
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
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;


LL dp[2][102][102][102];
int gd[102][102];
LL v[102];
int l[102],r[102];
vector<int> fac[102];

LL gcd(LL a, LL b){
    return b ? gcd(b,a%b) : a;
}

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) (ans *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }return ans;
}


int main(){
    int t;
    for(int i = 1; i <= 100; ++i)
        for(int j = 1; j <= 100; ++j)
            gd[i][j] = gcd(i,j);
    scanf("%d", &t);
    while(t--){
        int n,m,x;
        int num = 0;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &x);
            if(x) r[i] = l[i] = x;
            else l[i] = 1,r[i] = m, num++;
        }
        for(int j = 1; j <= m; ++j)
            scanf("%lld", &v[j]);
        memset(dp,0, sizeof dp);
        int now = 0;
        for(int i = l[3]; i <= r[3]; ++i)
            for(int j = l[2]; j <= r[2]; ++j)
                for(int k = l[1]; k <= r[1]; ++k)
                    dp[now][i][gd[i][j]][gd[k][gd[i][j]]]++;
        for(int ii = 4; ii <= n; ++ii){
            now ^= 1;
            for(int i = 1; i <= m; ++i)
                for(int j = i; j <= m; j+= i)
                    for(int k = j; k <= m; k += j){
                        if(dp[now^1][k][j][i] == 0) continue;
                        for(int t = l[ii]; t <= r[ii]; ++t)
                            (dp[now][t][gd[t][k]][gd[t][j]] += dp[now^1][k][j][i] * v[gd[t][i]] % mod)%=mod;
                        dp[now^1][k][j][i] = 0;
            }
        }
        LL ans = 0;
        for(int i = 1; i <= 100; ++i)
            for(int j = i; j <= 100; j += i)
                for(int k = j; k <= 100; k += j)
                    (ans += dp[now][k][j][i])%=mod;
        (ans *= qpow(qpow(m,mod-2), num)) %= mod;
        printf("%lld\n", ans%mod);
    }return 0;
}
