/*************************************************************************
	> File Name: POJ-3208.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月14日 星期六 17时09分34秒
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

int bits[20];
LL dp[20][10][10][2];

LL dfs(int pos, bool limit, int pre, int pre1, bool sta){
    if(pos == -1) return sta;
    if(!limit && dp[pos][pre][pre1][sta] != -1) return dp[pos][pre][pre1][sta];

    int up = limit ? bits[pos] : 9;
    LL tmp = 0;
    for(int i = 0; i <= up; ++i){
            tmp += dfs(pos-1, limit&&i==up, pre1,i,sta||(i == 6 && pre == 6 && pre1 == 6));
    }if(!limit) dp[pos][pre][pre1][sta] = tmp;
    return tmp;
}

LL solve(LL n){
    int pos = 0;
    if(n <= 0) return 0;
    while(n){
        bits[pos++] = n%10;
         n /= 10;
    }return dfs(pos-1, 1, 0, 0, 0);
}

int main(){
    int t;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        LL ans;
        LL l = 1,r = 1e18, mid;
        while(r >= l){
            mid = (r-l)/2 + l;
            if(solve(mid) >= n) 
                r = mid-1, ans = mid;
            else l = mid+1;
        }printf("%lld\n", ans);
    }
	return 0;
}
