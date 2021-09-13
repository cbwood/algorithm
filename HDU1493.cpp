/*************************************************************************
	> File Name: HDU1493.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 16时44分33秒
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

double dp[12][70], p[10];
int a[]={5, 12, 22, 29, 33, 38, 42, 46, 50 ,55};

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i <= 10; ++i)
            for(int j = 0; j <= 60; ++j) 
                dp[i][j] = 0;
        for(int i = 1; i <= 6; ++i)
            scanf("%lf",p+i), dp[1][i] = p[i];

        for(int i = 1; i <= 10; ++i){
            for(int k = 1; k <= 55; ++k)
                for(int j = 1; j <= 6; ++j)
                    dp[i][k+j] += dp[i-1][k] * p[j];
        }
        for(int i = 1; i <= 55; ++i)
            for(int j = 2; j <= 10; ++j)
                dp[j][i] = dp[j-1][i] + dp[j][i];
        for(int i = 0; i < 10; ++i)
            printf("%d: %.1f%%\n", a[i], dp[10][a[i]]*100);
        if(t)
        printf("\n");
    }
	return 0;
}
