#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
double a[maxn],b[maxn];
double ans[maxn*maxn];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        double y;
        scanf("%d %lf", &x, &y);
        a[x] += y;
    }scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x;
        double y;
        scanf("%d %lf", &x, &y);
        b[x] += y;
    }
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            ans[i+j] += a[i]*b[j];
    n = 0;
    for(int i = maxn*maxn-10; i >= 0; --i)
        if(fabs(ans[i]) > 1e-6)
            n++;
    printf("%d", n);
    for(int i = maxn*maxn-10; i >= 0; --i)
        if(fabs(ans[i]) > 1e-6)
            printf(" %d %.1f", i, ans[i]);
    return 0;
}
