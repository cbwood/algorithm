/*************************************************************************
	> File Name: LightOJ-1030.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 11时00分10秒
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

double dp[102];
int a[102];

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }memset(dp, 0, sizeof(dp));
        dp[n] = a[n];
        for(int i = n-1; i >= 1; --i){
            int up = min(6, n-i);
            for(int j = 1; j <= up; ++j)
                dp[i] += (dp[i+j] + a[i])/up;
        }
        printf("Case %d: %.6f\n",++kase, dp[1]);
    }
	return 0;
}
