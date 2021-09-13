/*************************************************************************
	> File Name: codeforce189-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月01日 星期一 15时33分37秒
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

int dp[66][66][66], w[66][66][66];

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            for(int k = 1; k <= n; ++k)
                scanf("%d", &w[i][j][k]);
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= m; ++i)
        for(int  k = 1; k <= n; ++k)
            for(int j = 1; j <= n; ++j)
                for(int l = 1; l <= n; ++l)
                    w[i][j][l] = min(w[i][j][l], w[i][j][k] + w[i][k][l]);
    for(int i = 1; i <= m; ++i)
        for(int  k = 1; k <= n; ++k)
            for(int j = 1; j <= n; ++j)
                for(int l = 1; l <= n; ++l)
                    dp[0][k][j] = min(dp[0][k][j], w[i][k][l] + w[i][l][j]);
    for(int i = 1; i <= n; ++i)
        for(int  k = 1; k <= n; ++k)
            for(int j = 1; j <= n; ++j)
                for(int l = 1; l <= n; ++l)
                    dp[i][j][l] = min(dp[i][j][l], dp[i-1][j][k] + dp[0][k][l]);
    while(r--){
        int u, v, w;
        cin >> u >> v >> w;
        w = min(w, n);
        int ans = 0x3f3f3f3f;
        for(int i = 0; i <= w; ++i)
            ans = min(ans, dp[i][u][v]);
        cout << ans << endl;
    }
	return 0;
}
