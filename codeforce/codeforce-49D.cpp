/*************************************************************************
	> File Name: codeforce-49D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月18日 星期六 23时46分07秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
typedef long long LL;

vector<int> w[maxn];
bool vis[maxn];
int a[maxn];
int num[maxn];

void dfs(int u){
	vis[u] = 1;
	for(auto &x: w[u])
		if(!vis[x]){
			num[x]--;
			if(num[x] == 0)
				dfs(x);
		}
}

int dfss(int u){
	int minx = a[u];
	vis[u] = 1;
	for(auto &x: w[u]){
		if(!vis[x])
			minx = min(minx,dfss(x));
	}return minx;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		w[i].emplace_back(x);
		num[x]++;
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i)if(num[i] == 0 && !vis[i]){
		dfs(i);
	}
	for(int i = 1; i <= n; ++i)if(!vis[i]){
		ans += dfss(i);
	}printf("%lld\n", ans);
}
