/*************************************************************************
	> File Name: HDU3366.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 18时56分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

double dp[1002][12];
struct ss{
    double x, y;
    bool operator < (const ss &q)const {
        return x/(x+y) > q.x /(q.x+q.y);
    }
}a[1002];

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n,m;
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i)
            scanf("%lf %lf",&a[i].x, &a[i].y);
        sort(a+1,a+1+n);
        memset(dp, 0, sizeof(dp));
        for(int i = n; i >= 1; --i)
            for(int j = 0; j <=m; ++j){
                dp[i][j] = a[i].x;
                if(i < n && j) dp[i][j] += dp[i+1][j-1] * a[i].y;
                if(i < n) dp[i][j] += dp[i+1][j] * (1 - a[i].x - a[i].y);
            }
        printf("Case %d: %.5f\n", ++kase, dp[1][m]);
    }
	return 0;
}
