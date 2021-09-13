/*************************************************************************
	> File Name: LightOJ-1317.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月08日 星期三 10时07分44秒
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
const LL mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int main(){
    int t, kase = 0;
    cin >> t;
    while(t--){
        int k,n,m;
        double p;
        cin >> n >> m >> k >>p;
        printf("Case %d: %.7f\n", ++kase, k*n*p);
    }
	return 0;
}
