/*************************************************************************
	> File Name: HDU-4389.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 13时31分18秒
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

int dp[10][90][90][90];
int bits[10];

int dfs(int pos, bool limit, int x, int t, int sum){
    if(pos == -1) return sum == t &&!x;
    if(!limit && dp[pos][x][t][sum] != -1) return dp[pos][x][t][sum];

    int ans = 0;
    int up = limit ? bits[pos] : 9;

    for(int i = 0; i <= up; ++i)
        ans += dfs(pos-1, limit && i == up, (x*10+i)%t,t, sum + i);
    if(!limit) dp[pos][x][t][sum] = ans;
    return ans;
}

int solve(int n){
    int pos = 0;
    if(n <= 0) return 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }int ans = 0;
    for(int i = 1; i <= pos*9; ++i)
        ans += dfs(pos-1, 1, 0, i, 0);
    return ans;
}

int main(){
    int t, kase = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n",++kase,solve(b)-solve(a-1));
    }
	return 0;
}
