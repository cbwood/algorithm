/*************************************************************************
	> File Name: LightOJ1095.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 17时02分40秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 1e3 + 10;

LL c[maxn][maxn];
LL f[maxn];

int main(){
	f[1] = 0;
	f[2] = f[0] = 1;
	for(int i = 3; i < maxn; ++i)
		f[i] = 1LL*(i-1)*(f[i-1] + f[i-2]) % mod;
	for(int i = 0; i < maxn; ++i){
		c[i][0] = c[i][i] = 1;
	}for(int i = 2; i < maxn; ++i)
		for(int j = 1; j < i; ++j)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	int t, kase = 0;
	scanf("%d", &t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d", &n,&m,&k);
		LL ans = 0;
		for(int i = 0; i <= n-m; ++i)
			ans = (ans + c[n-m][i]*f[n-k-i] % mod) % mod;
		ans = ans * c[m][k] % mod;
		printf("Case %d: %lld\n",++kase, ans);
	}return 0;
}
