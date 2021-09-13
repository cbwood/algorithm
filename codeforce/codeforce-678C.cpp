/*************************************************************************
	> File Name: codeforce-678C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月24日 星期二 21时10分56秒
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
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

LL gcd(LL a, LL b){
    return b ? gcd(b,a%b) : a;
}

LL LCM(LL a, LL b){
    return a /gcd(a,b) * b;
}

int main(){
    LL n, a, b, q, p;
    ios::sync_with_stdio(0);
    cin >> n >> a >> b >> p >> q;
    LL numa = n/a, numb = n /b, numab = n / LCM(a,b);
    numa -= numab;
    numb -= numab;
    LL ans = numa * p + numb*q + numab*max(p,q);
    cout << ans << endl;
	return 0;
}
