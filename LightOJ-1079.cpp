/*************************************************************************
	> File Name: LightOJ-1079.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月17日 星期二 15时16分04秒
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
int v[110];
double w[110];

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        double p;
        int n;
        scanf("%lf %d", &p, &n);
        int sum = 0;
        for(int i = 1; i <=n; ++i)
            scanf("%d %lf", &v[i], &w[i]), sum += v[i];
        for(int i = 1; i <= sum; ++i)
            dp[i] = 1;
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = sum ;j >= v[i]; --j)
                dp[j] =min(dp[j], dp[j-v[i]] + w[i] * (1-dp[j-v[i]]));
        for(int i = sum ;i >= 0; --i)
            if(dp[i] <= p) {
                printf("Case %d: %d\n", ++kase, i);
                break;
            }
    }
	return 0;
}
