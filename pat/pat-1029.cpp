#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn],b[maxn];

int main(){
    int n,m;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    int tar = (m+n+1)/2;
    int i = 1, j = 1, ans;
    while(i <= n && j <= m){
        ans = a[i] <= b[j] ? a[i++] : b[j++];
        if(i+j-2 == tar) break;
    }
    if(i <= n && i+j-2 < tar)
        ans = a[tar-m];
    else if(j <= m && i+j-2 < tar)
        ans = b[tar-n];
    printf("%d\n",ans);
    return 0;
}