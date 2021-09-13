/*************************************************************************
	> File Name: cf-168D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月25日 星期一 12时20分04秒
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

double dp[205][205][615];
int tmp = 300;
double p[215];
int a[215];

int main(){
    int n, l, k;
    scanf("%d %d %d", &n, &l, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%lf",p + i), p[i] /= 100;
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    dp[0][0][tmp+k] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            for(int t = 0; t <= 600; ++t){
                if(a[i] != -1){
                    int p1 = min(t+a[i], 600);
                    dp[i][j][p1] += dp[i-1][j-1][t] * p[i];
                    dp[i][j-1][t] += dp[i-1][j-1][t] * (1-p[i]);
                }else {
                    if(t) dp[i][j][t-1] += dp[i-1][j-1][t] * p[i];
                    dp[i][j-1][t] += dp[i-1][j-1][t] * (1-p[i]);
                }
            }
    double ans = 0;
    for(int i = l; i <= n; ++i)
        for(int j = tmp; j <= 610; ++j)
            ans += dp[n][i][j];
    printf("%.10f\n", ans);
	return 0;
}
