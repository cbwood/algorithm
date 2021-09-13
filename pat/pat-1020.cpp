#include<bits/stdc++.h>
using namespace std;

int a[100000],po[1000], io[10000];
int maxi;
int t;
void dfs(int l, int r, int u, int ll, int rr){
    maxi = max(maxi, u);
    int k = l;
    if(ll > rr) return ;
    while(io[k] != po[rr]) k++;
    a[u] = io[k];
    dfs(k+1,r,2*u+1,rr-(r-k),rr-1);
    dfs(l,k-1,2*u, ll, rr-(r-k)-1);
}

void bfs(int u){
    printf("%d",a[u]);
    queue<int> que;
    que.push(u);
    while(!que.empty()){
        int k = que.front();
        que.pop();
        if(2*k <= maxi && a[2*k]){
            printf(" %d", a[2*k]);
            que.push(2*k);
        }
        if(2*k+1 <= maxi&&a[2*k+1]){
            printf(" %d", a[2*k+1]);
            que.push(2*k+1);
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    t = n-1;
    for(int i = 0; i < n; ++i)
        scanf("%d", &po[i]);
    for(int i = 0; i < n; ++i)
        scanf("%d", &io[i]);
    dfs(0, n-1, 1, 0, n-1);
    bfs(1);
    return 0;
}
