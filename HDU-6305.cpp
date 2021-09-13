/*************************************************************************
	> File Name: HDU-6305.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月24日 星期二 13时58分58秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;

pair<int, int> a[maxn];
int stk[maxn], l[maxn], r[maxn];
bool vis[maxn];
LL inv[maxn], ans;

int dfs(int u){
    LL t = 1;
    if(l[u]) t += dfs(l[u]);
    if(r[u]) t += dfs(r[u]);
    ans = ans * inv[t] % mod;
    return t;
}

void build(int n) {
	int top=0;
	for(int i = 1; i < n+1; ++i) l[i]=0,r[i]=0,vis[i]=0;
	for(int i = 1; i < n+1; ++i) {
		int k=top;
		while (k>0&&a[stk[k-1]]>a[i]) --k;
		if (k) r[stk[k-1]]=i;
		if (k<top) l[i]=stk[k];
		stk[k++]=i;
		top=k;
	}
    for(int i = 1; i <= n; ++i) vis[l[i]] = vis[r[i]] = 1;
    int rt = 0;
    for(int i = 1; i <= n; ++i) if(!vis[i]) rt = i;
    dfs(rt);
}

int main(){
    int t;
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i) inv[i] = inv[mod%i] * (mod - mod/i) % mod;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            a[i] = make_pair(-x, i);
        }
        ans = n * inv[2] % mod;
        build(n);
        printf("%lld\n", ans);
    }
	return 0;
}
