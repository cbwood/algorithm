/*************************************************************************
	> File Name: codeforce-262D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 14时44分53秒
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
const int maxn = 52;

double dp[maxn][maxn][maxn];
double fi[maxn];
int a[maxn];

int main(){
    int n;
    double p;
    scanf("%d", &n);
    fi[0] = 1;
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i),fi[i] = fi[i-1] * i;
    sort(a+1,a+1+n);
    scanf("%lf", &p);
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= i; ++j)
            for(int k = 0; k <= p; ++k){
                if(i > j) dp[i][j][k] += dp[i-1][j][k];
                if(j && k >= a[i]) dp[i][j][k] += dp[i-1][j-1][k-a[i]];
            }
    double ans = 0;
    for(int j = 1; j <= n; ++j)
        for(int k = 1; k <= p; ++k)
            ans += dp[n][j][k] * fi[j] * fi[n-j];
    printf("%.4f\n", ans/fi[n]);
	return 0;
}
