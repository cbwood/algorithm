/*************************************************************************
	> File Name: LightOj-1246.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月23日 星期四 15时41分54秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int  maxn = 300+10;

LL dp[maxn][61],c[maxn][maxn];

void init(){
	for(int i = 1; i <maxn;++i){
		dp[i][1] = 1;
		for(int j = 2; j <= 60; ++j)
			dp[i][j] = (dp[i-1][j-1] * j + dp[i-1][j] * j) % mod;
	}c[0][0] =  1;
	for(int i = 1; i < maxn; ++i){
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
	}/*
	for(int i = 0; i <= 10; ++i){
		for(int j = 0; j <= 10; ++j)
			printf("%d ",c[i][j]);
		printf("\n");
	}*/
}

int main(){
	init();
	int t, kase =0;
	scanf("%d", &t);
	while(t--){
		int n,k, m;
		scanf("%d %d %d", &n,&m,&k);
		LL ans = 0;
		int x = (n+1)*(m+1)/2 ;
		int y = (n+1)*(m+1)-x;
		for(int i = 1; i <= k; ++i)
			for(int j = 1; j+i <= k; ++j)
				ans =(ans + c[k][i] * c[k-i][j] % mod * dp[x][i] % mod * dp[y][j]% mod)%mod;
		if(n==0&&m==0) ans = k;
		printf("Case %d: %lld\n", ++kase, ans);
	}return 0;
}
