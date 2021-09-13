/*************************************************************************
    > File Name: HDU-6442.cpp
    > Author: wood
    > Mail: cbcruel@gmail.com
    > Created Time: 2018年08月26日 星期日 08时49分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pr;
#define fi first
#define se second
#define mp make_pair

inline pr mul(pr a, pr b, LL mod, LL B){
    return mp((a.fi *b.fi % mod + a.se *b.se%mod*B%mod) % mod ,(a.fi *b.se%mod+a.se*b.fi%mod) % mod);
}

pr solve(LL a, LL b, LL B, LL mod,LL n){
    pr ans = mp(a,b);
    pr x = mp(a,b);n--;
    while(n){
        if(n&1) ans = mul(ans,x,mod,B);
        x = mul(x,x,mod,B);
        n >>= 1;
    }return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL n,p;
        pr x;
        scanf("%lld%lld%lld%lld", &x.fi, &x.se, &n,&p);
        LL tt = solve(x.fi,1,x.se,p,n).se;
        tt = (tt + p) % p;
        for(LL i = 2; i *i <= x.se; ++i)
            if(x.se%(i*i) == 0){
                while(x.se%(i*i) == 0){
					x.se /=(i*i);
					tt = tt * i % p;
				}
			}
        printf("1 %lld %lld\n",(tt%p+p)%p, x.se);
    }return 0;
}
