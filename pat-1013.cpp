#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3+10;
vector<int> w[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = 1;
    for(auto &x : w[u])
        if(!vis[x])
            dfs(x);
}

int main(){
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    while(m--){
        int x,y;
        scanf("%d %d", &x, &y);
        w[x].push_back(y);
        w[y].push_back(x);
    }while(k--){
        int x;
        scanf("%d", &x);
        int ans = 0;
        memset(vis,0,sizeof(vis));
        vis[x]=1;
        for(int i = 1; i <= n; ++i)
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        printf("%d\n",ans-1);
    }return 0;
}
