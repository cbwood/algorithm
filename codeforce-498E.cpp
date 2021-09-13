/*************************************************************************
	> File Name: codeforce-498E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 23时19分48秒
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
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

vector<int> w[maxn*2];
int a[maxn*2];
int num[maxn*2];
int inde[maxn*2];
int cnt;
void dfs(int u, int pre){
    a[++cnt] = u;
    inde[u] = cnt;
    num[u] = 1;
    for(auto x: w[u])
        if(x != pre)
            dfs(x, u), num[u] += num[x];
}

int main(){
    int n, q;

    scanf("%d %d", &n, &q);
    for(int i = 2; i <= n; ++i){
        int t;
        scanf("%d", &t);
        w[t].emplace_back(i);
    }cnt = 0;
    for(int i = 1; i <= n; ++i)
        sort(w[i].begin(),w[i].end());
    dfs(1,-1);
    while(q--){
        int u, k;
        scanf("%d %d", &u, &k);
        int ans = -1;
       // printf("num == %d\n", num[u]);
        if(k <= num[u])
            ans  = a[inde[u]+k-1];
        printf("%d\n", ans);
    }
	return 0;
}
