/*************************************************************************
	> File Name: ZOJ-3416.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 20时42分15秒
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

LL dp[20][20][2000];
int bits[20];

LL dfs(int pos, int sum, bool limit, int cur){
    if(pos == -1) return sum == 0;
    if(!limit && dp[pos][cur][sum] != -1) return dp[pos][cur][sum];

    if(sum < 0) return 0;

    int up = limit ? bits[pos] : 9;
    LL ans = 0;
    for(int i = 0; i <= up; ++i)
        ans += dfs(pos-1,sum + (pos-cur)*i, limit&&i == up, cur);
    if(!limit) dp[pos][cur][sum] = ans;
    return ans;
}

LL solve(LL n){
    int pos = 0;
    if(n < 0) return 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }
    LL ans = 0;
    for(int i = 0; i < pos; ++i)
        ans += dfs(pos-1,0,1, i);
    return ans-pos+1;
}

int main(){
    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while(t--){
        LL x, y;
        scanf("%lld %lld", &x, &y);
        printf("%lld\n",solve(y) - solve(x-1));
    }
	return 0;
}
