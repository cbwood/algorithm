/*************************************************************************
	> File Name: HDU-4778.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年10月18日 星期四 15时46分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int G,B,S;
int a[30][22];

const int maxn = (1<<22)+10;

int dp[maxn];

int dfs(int now, int x[10]){
	if(now == (1<<B)-1) return 0;
	if(dp[now] != maxn) return dp[now];
	int y[10];
	int ans = -maxn;
	for(int i = 0; i < B; ++i)if(!(now>>i&1)){
		for(int j = 1; j <= G; ++j) y[j] = x[j];
		for(int j = 1; j <= a[i][0]; ++j) y[a[i][j]]++;
		int sum = 0;
		for(int j = 1; j <= G; ++j){
			sum += y[j]/S;
			y[j] %= S;
		}if(sum == 0)
			ans = max(ans, -dfs(now|(1<<i), y));
		else ans = max(ans, sum + dfs(now|(1<<i), y));
	}dp[now] = ans;
	return ans;
}

int main(){
	while(scanf("%d %d %d", &G, &B, &S) != EOF &&(G||B||S)){
		for(int i = 0; i < maxn; ++i)
			dp[i] = maxn;
		for(int i = 0; i < B; ++i){
			scanf("%d", &a[i][0]);
			for(int j = 1; j <= a[i][0]; ++j)
				scanf("%d", &a[i][j]);
		}int x[10]={0};
		printf("%d\n", dfs(0, x));
	}return 0;
}
