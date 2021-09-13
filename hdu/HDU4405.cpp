/*************************************************************************
	> File Name: HDU4405.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月28日 星期四 22时33分08秒
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
const int maxn = 1e5 + 10;
int f[maxn];
double dp[maxn];

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(m == 0 && n == 0) break;
        memset(dp, 0, sizeof(dp));
        memset(f, -1, sizeof(f));
        while(m--){
            int x, y;
            scanf("%d %d", &x, &y);
            f[x] = y;
        }
        for(int i = n-1; i >= 0; --i){
            if(f[i] != -1)
                dp[i] = dp[f[i]];
            else {
                for(int j = 1; j <= 6; ++j)
                    if(i + j <= n)
                        dp[i] += dp[i+j] * 1.0 / 6;
            dp[i] += 1;
             }
        }printf("%.4f\n", dp[0]);
    }return 0;
}
