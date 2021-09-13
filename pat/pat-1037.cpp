#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1e5+10;
LL a[maxn],b[maxn];

int main(){
    int n,m;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%lld", &a[i]);
    scanf("%d",&m);
    for(int i = 0; i < m; ++i)
        scanf("%lld", &b[i]);
    sort(a,a+n);
    sort(b,b+m);
    LL ans = 0;
    int k = min(n,m);
    for(int i = 1; i <= min(n,m); ++i){
        if(a[n-i]*b[m-i] > 0)
            ans += a[n-i]*b[m-i];
        else break;
        k = min(n-i,m-i);
    }
    for(int i = 0; i < k;++i){
        if(a[i]*b[i] > 0)
            ans += a[i]*b[i];
        else break;
    }printf("%lld\n", ans);
    return 0;
}