/*************************************************************************
	> File Name: POJ-2282.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 14时36分41秒
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

int bits[20], dp[20][10];

int t;

int dfs(int pos, bool limit, bool lead, int num){
    if(pos == -1) return num;
    if(!limit && !lead && dp[pos][num] != -1) return dp[pos][num];
    int up = limit ? bits[pos] : 9;

    int ans = 0;
    for(int i = 0; i <= up; ++i){
        if(lead && i == 0) ans += dfs(pos-1, limit&&i==up,1, num);
        else ans += dfs(pos-1, limit&&i == up, 0, num + (i == t));
    }if(!limit && !lead) dp[pos][num] = ans; 
    return ans;
}

int solve(int n, int k){
    int pos = 0;
    t = k;
    if(n <= 0) return 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }return dfs(pos-1, 1, 1, 0);
}

int main(){
    int a,b;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d", &a, &b) != EOF){
        if(a == 0 && b == 0) break;
        if(a > b) swap(a,b);
        for(int i = 0; i < 9; ++i)
            printf("%d ", solve(b,i)-solve(a-1,i));
        printf("%d\n", solve(b,9)-solve(a-1,9));
    }
	return 0;
}
