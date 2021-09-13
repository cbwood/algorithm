/*************************************************************************
	> File Name: codeforce460-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月01日 星期四 13时53分30秒
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
const int maxn = 6e5 + 10;
int cnt = 0,f[maxn][28],head[maxn],deg[maxn];
int n, m;
char s[maxn];

struct ss{
    int to, next;
}edge[maxn];

void add(int u, int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void topo(){
    queue<int> q;
    for(int i = 1; i <= n; ++i)
    if(!deg[i]){
        q.push(i);
        f[i][s[i]-'a']++;
    }
    int num = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        num++;
        for(int st = head[u]; st != -1; st = edge[st].next){
            int v = edge[st].to;
            deg[v]--;
            if(!deg[v]) q.push(v);
            for(int j = 0;j < 26; ++j) f[v][j] = max(f[v][j], f[u][j] + (s[v]-'a' == j));
        }
    }if(num < n) printf("-1\n");
    else {
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < 26; ++j)
                ans = max(ans, f[i][j]);
        printf("%d\n", ans);
    }
}

int main(){
    memset(head, -1, sizeof(head));
    scanf("%d %d %s", &n, &m, s+1);
    int u, v;
    for(int i = 0; i < m; ++i){
        scanf("%d %d", &u, &v);
        deg[v]++;
        add(u, v);
    }topo();
	return 0;
}
