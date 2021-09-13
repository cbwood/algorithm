#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4+10;
vector<int> w[maxn];
int dp[maxn];
set<int> se;
int maxi = 0;
bool vis[maxn];

void dfs(int u, int d){
    if(d >= maxi){
        if(d > maxi){
            se.clear();
            se.insert(u);
            maxi = d;
        }else se.insert(u);
    }
    vis[u] = 1;
    for(auto &x : w[u])
        if(!vis[x])
            dfs(x, d+1);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n-1; ++i){
        int x,y;
        scanf("%d %d", &x, &y);
        w[x].push_back(y);
        w[y].push_back(x);
    }
    int num = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i]){
            dfs(i, 1);
            num++;
        }
    if(num > 1)
        printf("Error: %d components\n", num);
    else {
        memset(vis, 0, sizeof vis);
        set<int> ans(se.begin(),se.end());
        dfs(*se.begin(), 1);
        set<int> q;
        set_union(ans.begin(),ans.end(),se.begin(),se.end(),inserter(q,q.end()));
        for(auto it=q.begin() ; it!=q.end(); it++)
            printf("%d\n",*it);
    }
    return 0;
}
