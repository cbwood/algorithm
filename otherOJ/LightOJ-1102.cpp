/*************************************************************************
	> File Name: LightOJ-1102.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 18时55分31秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e6 + 10;
const LL mod = 1e9 + 7;

int ni[maxn],fi[maxn], inv[maxn];

LL C(int n, int m){
	if(n < m) return 0;
	return 1LL*fi[n] * ni[m]% mod * ni[n-m] % mod;
}

int main(){
	int t, kase = 0;
	inv[0]=inv[1]=1;//1 ~ n每个数的逆元
	for(int i = 2;i < maxn; ++i) inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	ni[0] = fi[0] = 1;
	for(int i = 1;i < maxn; ++i){
		fi[i] = 1LL*fi[i-1] * i % mod;
		ni[i] = 1LL*ni[i-1]*inv[i] % mod;
	}
	scanf("%d", &t);
	while(t--){
		int n,m;
		scanf("%d%d", &n,&m);
		printf("Case %d: %lld\n",++kase,C(n+m-1,m-1));
	}
}
