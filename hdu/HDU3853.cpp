/*************************************************************************
	> File Name: HDU3853.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月27日 星期三 21时09分45秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;

typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;

const int maxn = 1e3 + 10;
double dp[maxn][maxn];
double righ[maxn][maxn], down[maxn][maxn], noo[maxn][maxn];

int main(){
   int n,m;
    while(scanf("%d %d",&n, &m) != EOF){
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%lf %lf %lf", &noo[i][j], &righ[i][j], &down[i][j]);
        for(int i = n; i >= 1; --i)
            for(int j = m; j >= 1; --j){
                if(i == n && j == m) continue;
                if(fabs(1-noo[i][j]) < eps) continue;
                dp[i][j] = (dp[i+1][j] * down[i][j] + dp[i][j+1] * righ[i][j] + 2) / (1-noo[i][j]);
            }
        printf("%.3f\n", dp[1][1]);
    }return 0;
}
