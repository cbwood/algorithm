/*************************************************************************
	> File Name: HDU-4722.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 14时05分52秒
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

LL dp[20][200];
int bits[20];

LL dfs(int pos, bool limit , int sum){
    if(pos == -1) return sum%10 == 0;
    if(!limit && dp[pos][sum] != -1) return dp[pos][sum];

    LL ans = 0;
    int up = limit ? bits[pos] : 9;
    for(int i = 0; i <= up; ++i)
        ans += dfs(pos-1, limit && i == up, sum + i);
    if(!limit) dp[pos][sum] = ans;
    return ans;
}

LL solve(LL n){
    int pos = 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }return dfs(pos-1, 1, 0);
}

int main(){
    int t, kase = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while(t--){
        LL a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %lld\n", ++kase, solve(b)-solve(a-1));
    }
	return 0;
}
