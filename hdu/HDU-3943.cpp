/*************************************************************************
	> File Name: HDU-3943.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 09时03分37秒
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

LL dp[20][20][20];
int bits[20];
int X, Y;

LL dfs(int pos, bool limit, int x, int y){
    if(pos == -1) return x == X&&y == Y;
    if(!limit && dp[pos][x][y] != -1) return  dp[pos][x][y];

    LL ans = 0;
    int up = limit ? bits[pos] : 9;
    for(int i =0; i <= up; ++i)
        ans += dfs(pos-1, limit&&i == up, x + (i == 4 ? 1 : 0), y + (i == 7 ? 1 : 0));
    if(!limit) dp[pos][x][y] = ans;
    return ans;
}

LL solve(LL n){
    int pos = 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }return dfs(pos-1, 1, 0, 0);
}

LL cute(LL t, LL tt, LL k, LL P, LL Q){
    LL l = P+1,  r = Q, mid;
    LL ans;
    while(l <= r){
        mid = (r-l)/2+l;
        if(solve(mid)-tt>= k)
            r = mid-1, ans = mid;
        else l = mid+1;
    }return ans;
}

int main(){
    int t, kase = 0;
    LL P, Q, K;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld %d %d", &P, &Q, &X, &Y);
        LL t = solve(Q) , tt = solve(P);
        int n;
        scanf("%d", &n);
        printf("Case #%d:\n", ++kase);
        while(n--){
            scanf("%lld", &K);
            if(t-tt < K) puts("Nya!");
            else printf("%lld\n", cute(t,tt,K,P, Q));
        }
    }
	return 0;
}
