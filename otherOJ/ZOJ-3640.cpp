/*************************************************************************
	> File Name: ZOJ-3640.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月18日 星期三 09时42分35秒
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
const int maxn = 1e6 + 10;
#define sqr(x) (x)*(x)

double dp[maxn];
int c[maxn], t[maxn];
int n;

double dfs(int f){
    if(dp[f] > 0) return dp[f];
    dp[f] = 0;
    for(int i = 1; i <= n; ++i)
        if(f > c[i]) dp[f] += t[i];
        else dp[f] += 1+dfs(f+c[i]);
    dp[f] /= n;
    return dp[f];
}

int main(){
    int  f;
    while(scanf("%d %d", &n, &f) != EOF){
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &c[i]);
            sum = max(sum, c[i]);
            t[i] = (int)floor((1+sqrt(5))/2 * sqr(c[i]));
        }memset(dp, 0, sizeof(dp));
        printf("%.3f\n", dfs(f));
    }
	return 0;
}
