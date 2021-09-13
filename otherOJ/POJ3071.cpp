/*************************************************************************
	> File Name: POJ3071.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月18日 星期一 21时54分33秒
 ************************************************************************/

// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 7;
double dp[maxn + 5][1 << maxn + 4];
double p[1 << maxn + 5][1 << maxn + 4];

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n != -1){
        for(int i = 0; i < (1 << n); ++i)
            for(int j = 0; j < (1 << n); ++j)
                scanf("%lf", &p[i][j]);
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < (1 << n); ++i)
            dp[0][i] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < (1 << n); ++j)
                for(int k = 0; k < (1 << n); ++k)
                    if(((j >>(i-1))^1) == (k >>(i-1)))
                        dp[i][j] += dp[i-1][k] * dp[i-1][j] * p[j][k];
        double ans = 0;
        int index = -1;
        for(int i = 0; i < (1 << n); ++i)
            if(dp[n][i] > ans){
                ans = dp[n][i];
                index = i + 1;
            }
        printf("%d\n", index);
    }return 0;
}
