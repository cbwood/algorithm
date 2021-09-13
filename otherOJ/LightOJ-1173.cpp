/*************************************************************************
	> File Name: LightOJ-1173.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月21日 星期二 08时49分55秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long LL;
LL f[52][52], g[52][52];

void init(){
	f[1][1] = g[1][1] = 1;
	for(int n = 2; n <= 50; ++n)
		for(int i = 1; i <= n; ++i){
			for(int j = i; j < n; ++j) f[n][i] += g[n-1][j];
			for(int j = 1; j < i; ++j) g[n][i] += f[n-1][j];
		}
}

int main(){
	init();
	int t,kase = 0;
	scanf("%d", &t);
	while(t--){
		int n,m;
		scanf("%d%d", &n,&m);
		LL ans = 0;
		if(m == 1){
			ans = g[n-1][2];
			if(n <= 2) ans = 1;
		}else for(int i = 1; i < m; ++i)
			ans += f[n-1][i];
		printf("Case %d: %llu\n", ++kase, ans);
	}return 0;
}
