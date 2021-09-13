#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+20;
const int INF = 1e8 + 10;

int w[maxn][maxn];
int num[maxn];
int dis[maxn];
bool vis[maxn];
int ansgo,ansbc;
vector<int> pre[maxn];
int an[maxn], bn[maxn],cnt;

void dijkstra(int n, int ed){
    for(int i = 0; i <= n; ++i)
        dis[i] = w[ed][i];
    dis[ed] = 0;
    for(int i = 0; i < n; ++i){
        int u = -1,mini = INF;
        for(int j = 0; j <= n; ++j)
            if(!vis[j] && dis[j] < mini){
                u = j;
                mini = dis[j];
            }
        if(u == -1) break;
        vis[u] = 1;
        for(int j = 0; j <= n; ++j)
            if(!vis[j] && dis[u] + w[u][j] < dis[j]){
                dis[j] = dis[u] + w[u][j];
                pre[j].clear();
                pre[j].push_back(u);
            }else if(!vis[j] && dis[u] + w[u][j] == dis[j]){
                pre[j].push_back(u);
            }
    }
}

void dfs(int u, int co, int ango, int anbc, int nu, int ed){
    an[nu] = u;
    if(u == ed){
        if(ango < ansgo||(ansgo == ango && ansbc > anbc)){
            ansgo = ango;
            ansbc = anbc;
            cnt = nu-1;
            for(int i = 0; i <= nu; ++i)
                bn[i] = an[i];
        }return;
    }
    for(auto &x : pre[u]){
        if(co > num[x]){
            if(anbc > 0){
                dfs(x, co, ango + max(0,-1*anbc+co-num[x]),  max(0, anbc-co+num[x]), nu+1, ed);
            }else{
                dfs(x, co, ango+co-num[x], anbc, nu+1, ed);
            }
        }else {
                dfs(x, co, ango, anbc + max(0, num[x]-co), nu+1, ed);
        }
    }
}

int main(){
    int co,n,m,ed;
    ansgo = ansbc = INF;
    scanf("%d %d %d %d", &co, &n, &ed, &m);
    co /= 2;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &num[i]);
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            w[i][j] = INF;
    while(m--){
        int x,y,t;
        scanf("%d %d %d", &x, &y, &t);
        w[x][y] = w[y][x] = t;
    }
    dijkstra(n,ed);
    dfs(0, co, 0, 0,0, ed);
    printf("%d 0", ansgo);
    for(int i = 1; i <= cnt+1; ++i)
        printf("->%d",bn[i]);
    printf(" %d\n", ansbc);
    return 0;
}

/*
10 3 3 5
6 7 10
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/
