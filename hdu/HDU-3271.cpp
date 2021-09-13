/*************************************************************************
	> File Name: HDU-3271.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 16时15分51秒
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

int dp[70][70][310];
int bits[70];
int B, M;

int dfs(int pos, int sum, bool limit){
    if(pos == -1) return sum == 0;
    if(sum < 0) return 0;
    if(!limit && dp[pos][B][sum] != -1) return dp[pos][B][sum];
    int up = limit ? bits[pos] : B-1;
    int tmp = 0;
    for(int i = 0; i <= up; ++i)
        tmp += dfs(pos-1, sum-i, limit&&i == up);
    if(!limit) dp[pos][B][sum] = tmp;
    return tmp;
}

int solve(int n){
    if(n < 0) return 0;
    int pos = 0;
    while(n){
        bits[pos++] = n%B;
        n /= B;
    }return dfs(pos-1, M, 1);
}

int main(){
    int op, L, R, kase = 0, k;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d %d %d %d", &op, &L, &R, &B, &M) != EOF){
        printf("Case %d:\n", ++kase);
        if(L > R) swap(L, R);
        int x = solve(L-1), y = solve(R);
        if(op == 1)
            printf("%d\n", y-x);
        else {
            scanf("%d", &k);
            if(y-x < k) puts("Could not find the Number!");
            else {
                int l = L-1, r = R;
                while(l +1 < r){
                    int mid = (r-l)/2 + l;
                    if(solve(mid)-x >= k){
                        r = mid;
                    }else l = mid;
                }printf("%d\n", r);
            }
        }
    }
    return 0;
}
