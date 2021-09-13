/*************************************************************************
	> File Name: ZOJ-3822.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月18日 星期三 10时56分50秒
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

double dp[2502][52][52];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        memset(dp, 0, sizeof(dp));
        dp[1][1][1] = 1;
        double ans = 0;
        for(int i = 1; i <= n*m; ++i){
            for(int j = 1; j <= n; ++j)
                for(int k = 1; k <= m; ++k)
                    if(dp[i][j][k] > 0){
                        if(j*k < n*m) dp[i+1][j][k] += dp[i][j][k] *(j*k-i) / (n*m-i);
                        dp[i+1][j+1][k] += dp[i][j][k] * (n-j)*k/(n*m-i);
                        dp[i+1][j][k+1] += dp[i][j][k] *(m-k)*j/(n*m-i);
                        dp[i+1][j+1][k+1] += dp[i][j][k] * (n-j)*(m-k)/(n*m-i);
                    }
        }for(int i = 1; i <= n*m; ++i)
            ans += dp[i][n][m] * i;
        printf("%.8f\n", ans);
    }
	return 0;
}
