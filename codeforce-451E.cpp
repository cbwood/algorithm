/*************************************************************************
	> File Name: codeforce-451E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月27日 星期五 20时10分59秒
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
const double Cc = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int n;
LL f[30], s;

LL qpow(LL x, LL n){
    LL ans = 1;
    while(n){
        if(n&1) ans = ans * x %mod;
        n >>= 1;
        x = x*x%mod;
    }return ans;
}

LL inv(LL x){
    return qpow(x, mod-2);
}

LL C(LL n,LL m){
    if (m>n) return 0LL;
    LL up=1LL,down=1LL;
    for (LL i=n-m+1;i<=n;++i) up=up*i%mod;
    for (LL i=1;i<=m;++i) down=down*i%mod;
    return up*inv(down)%mod;
}
LL lucas(LL n,LL m){//C(n, m) % mod, mod必须是质数
    if (m>n) return 0LL;
    LL ans=1;
    for (;m;n/=mod,m/=mod)
    ans=ans*C(n%mod,m%mod)%mod;
    return ans;
}

int main(){
    while(scanf("%d %lld", &n, &s) != EOF){
        LL sum = 0;
        for(int i = 0; i < n; ++i)
            scanf("%lld", &f[i]);
        LL ans =0 ;
        for(int i = 0; i < (1 << n); ++i){
            LL tmp = s;
            int ss = 1;
            for(int j = 0; j < n; ++j)
                if(i&(1<<j)){
                    ss++;
                    tmp -= (f[j]+1);
                }if(tmp < 0) continue;
            if(ss&1) ans = (ans + lucas(tmp+n-1,n-1))%mod;
            else ans = (ans - lucas(tmp+n-1,n-1))%mod;
        }printf("%lld\n", (ans%mod+mod)%mod);
    }
	return 0;
}
