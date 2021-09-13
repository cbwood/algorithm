/*************************************************************************
	> File Name: POJ2151.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月24日 星期日 22时21分37秒
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
const int maxn = 1000 + 10;

double dp[maxn][35][35];
double s[maxn][35], p[maxn][35];

int main(){
    int m, t, n;
    while(scanf("%d %d %d", &m, &t, &n) != EOF){
        if(m == 0 && n == 0 && t == 0)
            break;
        for(int i = 1; i <= t; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%lf", &p[i][j]);
        for(int i = 1; i <= t; ++i){
            dp[i][0][0] = 1.0;
            for(int j = 1; j <= m; ++j){
                dp[i][j][0] = dp[i][j-1][0] * (1- p[i][j]);
            for(int j = 1; j <=m; ++j)
                for(int k = 1; k <= j; ++k)
                dp[i][j][k] = dp[i][j-1][k] *(1 - p[i][j]) + dp[i][j-1][k-1] * p[i][j];
            }
            s[i][0] = dp[i][m][0];
            for(int j = 1; j <= m; ++j)
                s[i][j] = s[i][j-1] + dp[i][m][j];
        }
        double p1 = 1, p2 = 1;
        for(int i = 1; i <= t; ++i){
            p1 *= (1 - s[i][0]);
            p2 *= (s[i][n-1] - s[i][0]);
        }
        printf("%.3f\n", p1-p2);
    }return 0;
}
