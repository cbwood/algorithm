/*************************************************************************
	> File Name: POJ-3286.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 19时50分36秒
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

LL dp[20][10];
int bits[20];

LL dfs(int pos, bool limit , bool lead, int num){
    if(pos == -1) return num;
    if(!limit && !lead && dp[pos][num] != -1) return dp[pos][num];

    int up = limit ? bits[pos] : 9;
    LL ans = 0;
    for(int i = 0; i <= up; ++i){
        if(lead && i == 0) ans += dfs(pos-1, limit&&i==up,1,num);
        else ans += dfs(pos-1,limit&&i==up, 0,num+(i == 0));
    }if(!limit && !lead) dp[pos][num] = ans;
    return ans;
}

LL solve(LL n){
    int pos = 0;
    if(n < 0) return 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }return dfs(pos-1, 1, 1, 0)+1;
}

int main(){
    memset(dp, -1, sizeof(dp));
    LL n, m;
    while(scanf("%lld %lld", &n, &m) != EOF){
        if(n == -1 && m == -1) return 0;
        printf("%lld\n",solve(m) - solve(n-1));
    }
	return 0;
}
