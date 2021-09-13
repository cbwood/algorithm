/*************************************************************************
	> File Name: LightOJ-1064.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 14时17分35秒
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

LL dp[25][150], fi[25];

LL gcd(LL a, LL b){
    return b ? gcd(b, a%b) : a;
}


void init(){
    dp[0][0] = fi[0] = 1;
    for(int i = 1; i < 25; ++i)
        for(int j = i; j <= i*6; ++j){
            for(int k = 1; k <= 6 && k <= j; ++k)
                dp[i][j] += dp[i-1][j-k];
        }
    for(int i = 1; i < 25; ++i)
        for(int j = i*6; j >= 0; --j)
            dp[i][j] = dp[i][j] + dp[i][j+1];
    for(int i = 1; i <= 24; ++i)
        fi[i] = fi[i-1] * 6;
}

int main(){
    init();
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n, x;
        scanf("%d %d", &n, &x);
        LL t= gcd(dp[n][x], fi[n]);
        printf("Case %d: %lld", ++kase, dp[n][x]/t);
        if(fi[n]/t > 1)
            printf("/%lld",fi[n]/t);
        printf("\n");
    }
	return 0;
}
