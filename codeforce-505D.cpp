/*************************************************************************
	> File Name: codeforce-505D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月19日 星期日 22时51分26秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

bool w[800][800];
typedef long long LL;

LL a[1000];
bool vis[1000];

LL gcd(LL a,LL b){
	return b ? gcd(b,a%b) : a;
}

int cnt[1000];

int num, n;
bool check;

bool dfs(int i, int pre){
	if(num == n) check = true;
	if(check) return check;
	bool t;
	for(int x = 1; x <= n && !check; ++x)if(w[i][x] && !vis[x]){
		vis[x] = 1;
		num++;
		t = false;
		if(a[x] < a[i] && (pre==-1 || a[pre] > a[x])){
			 dfs(x,i);
			 t = true;
		}
		if(a[x] > a[i] && (pre == -1 || a[pre] < a[x])){
			t = dfs(x,i);
		t = true;
		}if(!t) w[i][x] = 0;
		num--;
		vis[x] = 0;
	}return t;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	bool sx = true;
	for(int i = 1; i <= n; ++i){
		bool sxx = false;
		for(int j = 1; j <= n; ++j)
			if(gcd(a[i],a[j]) > 1) w[i][j] = 1,sxx = true;
		if(!sxx) sx = false;
	}
	check = false;
	if(sx)
	for(int i = 1; i <= n; ++i){
		num = 1;
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		dfs(i, -1);
		if(check) break;
	}if(check) puts("YES");
	else puts("NO");
	return 0;
}
