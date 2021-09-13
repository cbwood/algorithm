/*************************************************************************
	> File Name: LightOJ-1226.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月21日 星期二 09时48分28秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e6 + 10;

LL fi[maxn], inv[maxn];

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
	fi[0] =1;
	for(int i = 1; i < maxn; ++i)
		fi[i] = fi[i-1] * i % mod;
	inv[maxn-1]=qpow(fi[maxn-1],mod-2);//阶乘逆元
	for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}

LL C(int n, int m){
	if(n < m) return 0;
	return fi[n] * inv[m] % mod * inv[n-m] % mod;
}

int main(){
	int t, kase = 0;
	init();
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		LL ans = 1;
		LL num = 1;
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d", &x);
			ans = ans * C(num-1+x-1,x-1) % mod;
			num += x;
		}printf("Case %d: %lld\n", ++kase, ans);
	}return 0;
}
