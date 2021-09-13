/*************************************************************************
	> File Name: codeforce-55D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月13日 星期五 14时20分19秒
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
const int mod = 2520;
const int maxn = 1e5 + 10;

int bits[70];
LL dp[70][50][2550];
int Hash[2540];

LL gcd(LL a, LL b){
    return b ? gcd(b,a%b): a;
}

LL lcm(LL a, LL b){
    return a/gcd(a,b)*b;
}

LL dfs(int gd, LL n, bool limit, int pos){
   if(pos == -1) return n % gd == 0;
    if(!limit && dp[pos][Hash[gd]][n] != -1) return dp[pos][Hash[gd]][n];

    LL tmp = 0;
    int up = limit ? bits[pos] : 9;
    for(int i = 0; i <= up; ++i){
        tmp += dfs(i?lcm(i,gd): gd, (n*10+i)%mod, limit&&i == up, pos-1);
    }if(!limit) dp[pos][Hash[gd]][n] = tmp;
    return tmp;
}

LL solve(LL n){
    int pos = 0;
    while(n){
        bits[pos++] = n%10;
        n /= 10;
    }return dfs(1, 0, 1, pos-1);
}

int main(){
    int cnt = 0;
    for(int i = 1; i <= mod; ++i)
        if(mod%i == 0) Hash[i] = cnt++;
    int t;
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    while(t--){
        LL l,r;
        cin >> l >> r;
        cout << solve(r)-solve(l-1) << endl;
    }
	return 0;
}
