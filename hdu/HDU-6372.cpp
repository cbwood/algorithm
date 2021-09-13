/*************************************************************************
	> File Name: HDU-6372.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月10日 星期五 08时56分24秒
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

LL inv[maxn],fi[maxn],ni[maxn];
vector<int> pri;
bool vis[maxn*15];

void init(){
    for(int i = 2; i < maxn*15; ++i){
        if(!vis[i]) pri.emplace_back(i);
        for(auto &x : pri){
            if(x*i >= maxn*15) break;
            vis[i*x] = 1;
            if(i % x == 0) break;
        }
    }
    inv[0]=inv[1]=fi[0] = fi[1] = 1;
    for(int i = 2;i < maxn; ++i) 
        inv[i]=inv[mod%i]*(mod-mod/i)%mod, fi[i] = fi[i-1] * i % mod;
}

LL qpow(LL x, LL n){
    LL ans = 1;
    x %= mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int main(){
    int t;
    init();
    scanf("%d", &t);
    while(t--){
        int c,n,k;
        scanf("%d %d %d", &c, &n, &k);
        LL ans = 0;
        int p = pri[c-1];
        LL base = p;
        for(int i = 1; i <= k; ++i){
            base = base * (p+i) % mod * inv[i+1] % mod;
            if(base == 1)
                (ans += n) %= mod;
            else (ans += (qpow(base, n+1) - base + mod) % mod* qpow(base-1, mod-2) % mod) %= mod;
        }printf("%lld\n", ans);
    }
	return 0;
}
