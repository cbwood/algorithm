#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
#define pb(x) push_back(x)
const int INF = 1e9;
bool vis[maxn];
int d[maxn];
int num[maxn];
int a[maxn][maxn];
int w[maxn], wi[maxn];

void dijkstra(int st, int ed, int n){
    for(int i = 0; i < n; ++i)
        d[i] = a[st][i];
    wi[st] = w[st];
    d[st] = 0;
   // vis[st] = 1;
    num[st] = 1;
    for(int i = 1; i < n; ++i){
        int u = -1, minx = INF;
        for(int j= 0; j < n; ++j)
            if(!vis[j] && d[j] < minx){
                u = j;
                minx = d[j];
            }
        if(u == -1) break;
        vis[u] = 1;
        for(int j = 0; j < n; ++j)
            if(!vis[j]){
                if(d[j] > d[u] + a[u][j]){
                    d[j] = d[u] + a[u][j];
                    wi[j] = wi[u] + w[j];
                    num[j] = num[u];
                }else if(d[j] == d[u] + a[u][j]){
                    num[j] += num[u];
                    wi[j] = max(wi[j], wi[u] + w[j]);
                }
            }
    }return ;
}

int main(){
    int n,m,st,ed;
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    for(int i = 0; i < n; ++i)
        scanf("%d", &w[i]);
    for(int i = 0; i < maxn;i++)
        for(int j = 0; j < maxn; j++)
            a[i][j] = INF,a[i][i] = 0;
    while(m--){
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        a[v][u] = a[u][v] = w;
    }dijkstra(st, ed, n);
   // printf("%d\n", d[ed]);
    printf("%d %d\n", num[ed], wi[ed]);
    return 0;
}
