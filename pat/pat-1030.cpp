#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
const int INF = 1e9;
int dis[maxn][maxn],cost[maxn][maxn];
int n,m,s,t;
int d[maxn],c[maxn], pre[maxn];
bool vis[maxn];

void dijkstra(){
    memset(pre, -1, sizeof(pre));
    for(int i = 0; i < n; ++i)
        d[i] = dis[s][i],c[i] = cost[s][i];
    d[s] = 0;
    c[s] = 0;
    vis[s] = 1;
    for(int i = 1; i < n; ++i){
        int u=-1,minx = INF;
        for(int j = 0 ; j <  n; ++j)
            if(!vis[j] && minx > d[j]){
                minx = d[j];
                u = j;
            }
        if(u == -1) break;
        vis[u] = 1;
        for(int j = 0; j < n; ++j)
            if(!vis[j]){
                if(d[j] > d[u] + dis[u][j]){
                    d[j] = d[u] + dis[u][j];
                    c[j] = c[u] + cost[u][j];
                    pre[j] = u;
                }else if(d[j] == d[u] + dis[u][j] && c[j] > c[u] + cost[u][j]){
                    d[j] = d[u] + dis[u][j];
                    c[j] = c[u] + cost[u][j];
                    pre[j] = u;
                }
            }
    }   
}

void dfs(int u){
    if(pre[u] == -1){
        printf("%d ",u);
        return;
    }
    dfs(pre[u]);
    printf("%d ",u);
}

int main(){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    memset(dis, 0x3f, sizeof(dis));
    memset(cost, 0x3f, sizeof(cost));
    for(int i = 0; i < m; ++i){
        int x,y,d,c;
        scanf("%d %d %d %d", &x, &y, &d, &c);
        dis[x][y] = dis[y][x] = d;
        cost[x][y] = cost[y][x] = c;
    }
    dijkstra();
    printf("%d ",s);
    dfs(t);
    printf("%d %d\n",d[t],c[t]);
    return 0;
}