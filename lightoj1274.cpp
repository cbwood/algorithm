/*************************************************************************
	> File Name: lightoj1274.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月14日 星期四 23时00分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 15000 + 10;
double dp[2][maxn][2];

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n, s;
        scanf("%d %d", &n, &s);
        int yes = s - 2 * n;
        int no = n - yes;
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >= 0; --i){
            int maxi = min(i, yes), mini = max(0, i - no);
            int ret = n - i;
            int now = i % 2, nxt = (i + 1) % 2;
            memset(dp[now], 0, sizeof(dp[now]));
            for(int j = mini; j <= maxi; ++j){
                double p1 = 1.0 * (yes - j) / ret;
                double p2 = 1.0 * (no - i + j) / ret;
                dp[now][j][0] = dp[nxt][j+1][0] * p1 + (dp[nxt][j][1] + 1 ) * p2;
                dp[now][j][1] = dp[nxt][j][1] * p2 +(dp[nxt][j+1][0] +1) * p1;
            }
        }printf("Case %d: %.7f\n", ++kase, dp[0][0][0]);
    }return 0;
}
