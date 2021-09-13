/*************************************************************************
	> File Name: codeforce460-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年02月01日 星期四 20时11分42秒
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

void exgcd(LL a, LL b, LL &x, LL &y){
    if(b){
        exgcd(b, a % b, y, x);
        y -= a / b * x;
        return;
    }x = 1;
    y = 0;
}

LL inv(LL a, LL b){
    LL x, y;
    exgcd(a, b, x, y);
    return (x % b + b) % b;
}

int main(){
    LL a, b, x, p;
    cin >> a >> b >> p >> x;
    LL P = p * (p - 1);
    LL inva = inv(a, p);
    LL cur = b;
    LL ans = 0;
    for(int j = 1; j < p; ++j){
        cur = (cur * inva) % p;
        LL y = ((j - cur) % p + p) % p;
        y = y * (p-1) + j;
        if(y <= x) ans += 1 + (x - y) / P; 
    }cout << ans << endl;
	return 0;
}
