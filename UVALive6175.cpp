/*************************************************************************
	> File Name: UVALive6175.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 15时01分15秒
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

double dp[2][2002][1001];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int op, n;
        double l,r;
        scanf("%d %d %lf %lf", &op, &n, &l, &r);
        memset(dp, 0, sizeof(dp));
        dp[0][1000][0] = 1;
        int tmp = 0;
        for(int i = 1; i <= n; ++i){
            tmp ^= 1;
            for(int j = 1000 - i; j <= 1000+i; ++j)
                for(int k = max(0, j-1000); k <= i; ++k){
                    dp[tmp][j][k] = dp[tmp^1][j][k] * (1-l-r);
                    dp[tmp][j][k] += dp[tmp^1][j-1][k] * r;
                    dp[tmp][j][k] += dp[tmp^1][j+1][k] * l;
                    if(j - 1000 == k)
                        dp[tmp][j][k] += dp[tmp^1][j-1][k-1] * r;
                }
        }
        double ans = 0;
        for(int i = 1000-n; i <= 1000+n; ++i)
            for(int k = 0; k <= n; ++k)
                ans += dp[tmp][i][k]*k;
        printf("%d %.4f\n", op, ans);
    }
	return 0;
}
