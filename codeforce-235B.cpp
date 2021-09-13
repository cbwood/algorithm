/*************************************************************************
	> File Name: codeforce-235B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 11时16分43秒
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

double dp[maxn], p[maxn];

int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%lf", &p[i]);
        ans += p[i];
    }for(int i = 2; i <= n; ++i){
        dp[i] = (dp[i-1] + p[i-1]) * p[i];
        ans += dp[i] * 2;
    }printf("%.6f\n" ,ans);
	return 0;
}
