/*************************************************************************
	> File Name: POJ-1322.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 16时31分29秒
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

double dp[2][105];

int main(){
    int c, n, m;
    while(scanf("%d", &c) != EOF && c){
        scanf("%d %d", &n, &m);
        if(m > n || m > c || (n-m)&1){
            puts("0.000");
            continue;
        }
        if(n > 500) n = 500 - (n&1);
        int t = 1;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[1][1]  = 1;
        for(int i = 2; i <= n; ++i){
            t ^= 1;
            dp[t][0] = dp[t^1][1]/c;
            dp[t][c] = dp[t^1][c-1]/c;
            for(int j = 1; j <= i && j < c; ++j)
                dp[t][j] = dp[t^1][j+1] * (j+1)/c + dp[t^1][j-1] * (c-j+1)/c;
        }
        printf("%.3f\n", dp[n&1][m]);
    }
	return 0;
}
