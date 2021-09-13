/*************************************************************************
	> File Name: LightOJ-1170.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月20日 星期一 08时55分49秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e6 + 10;
const LL mod = 1e8 + 7;
const LL INF = 1e10;

LL cat[maxn];
LL fac[maxn];

LL qpow(LL x, LL n){
    LL ans = 1;
    x = x % mod;
    while(n){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }return ans;
}

int main(){
	int t, kase = 0;
	scanf("%d", &t);
	cat[1] = 1;
	for(int i = 2; i < maxn; ++i)
		cat[i] = cat[i-1] * (4*i-2) % mod * qpow(i+1, mod-2) % mod;
	int x = 0;
	for(int i = 2;i <= maxn/10; ++i){
		LL t = i;
		for(int j = 1; j <= 60; ++j){
			t = t * i;
			if(t > INF || t <= 0) break;
			fac[x++] = t;
		}
	}sort(fac,fac+x);
	x = unique(fac,fac+x) - fac;
	while(t--){
		LL a, b;
		scanf("%lld %lld", &a, &b);

		int r = upper_bound(fac,fac+x,b) - fac;
		int l = lower_bound(fac,fac+x, a)- fac;
		//if(fac[r] != b) r--;
		//if(fac[l] != a) l++;
		int num = r-l;
		printf("Case %d: %lld\n",++kase, cat[num]);
	}return 0;
}
