#include<bits/stdc++.h>
using namespace std;

const int maxn = 1002;
#define pb push_back

vector<int> w[maxn];
int ans[maxn];

void dfs(int x, int d){
    if(w[x].size() == 0){
        ans[d]++;
        return ;
    }
    for(auto &u : w[x])
        dfs(u, d+1);
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int lsum = n-m;
    while(m--){
        int u,k;
        scanf("%d %d", &u, &k);
        while(k--){
            int x;
            scanf("%d", &x);
            w[u].pb(x);
        }
    }
    dfs(1, 1);
    printf("%d", ans[1]);
    int sum = ans[1];
    for(int i = 2; sum <
     lsum; sum += ans[i],++i)
        printf(" %d", ans[i]);
    printf("\n");
    return 0;
}
