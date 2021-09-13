/*************************************************************************
	> File Name: HDU5236.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 20时04分46秒
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

double dp[maxn];

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n,x;
        double p;
        scanf("%d %lf %d", &n, &p, &x);
        for(int i = 1; i <= n; ++i)
            dp[i] = (dp[i-1]+1)/(1-p);
        double ans = mod*1.0;
        for(int i = 1; i <= n; ++i){
            int k = n/i,t=n%i;
            ans = min(ans, dp[k]*(i-t) + dp[k+1] * t + x*i);
        }printf("Case #%d: %f\n", ++kase, ans);
    }
	return 0;
}
