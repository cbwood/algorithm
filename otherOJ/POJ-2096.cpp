/*************************************************************************
	> File Name: POJ-2096.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 18时50分27秒
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
const int maxn = 1e3 + 10;

double dp[maxn][maxn];

int main(){
    int n, s;
    while(scanf("%d %d", &n ,&s) != EOF){
        dp[n][s] = 0;
        for(int i = n; i >= 0; --i)
            for(int j = s; j >= 0; --j){
                if(i == n && j == s) continue;
                dp[i][j] = (dp[i][j+1]*i*(s-j) + dp[i+1][j]*(n-i)*j + dp[i+1][1+j]*(n-i)*(s-j) + n*s)/(n*s - i*j);
            }printf("%.4f\n", dp[0][0]);
    }
	return 0;
}
