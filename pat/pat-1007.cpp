#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int a[maxn], dp[maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int ans = a[1],ansx=a[1],ansy=a[1];
    int pre = 1;
    for(int i = 1; i <= n; ++i){
        if(a[i] + dp[i-1] < 0){
            dp[i] = 0;
            pre = i+1;
        } else {
            dp[i] = dp[i-1]+a[i];
            if(dp[i] > ans){
                ans = dp[i];
                ansx = a[pre];
                ansy = a[i];
            }
        }
        if(a[i] > ans){
            ans = a[i];
            ansx = a[i];
            ansy = a[i];
        }
    }
    if(ans < 0)
        ans=0,ansx=a[1],ansy=a[n];
    printf("%d %d %d", ans, ansx, ansy);
    return 0;
}
