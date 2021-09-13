/*************************************************************************
	> File Name: LightOJ-1342.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月14日 星期二 08时57分14秒
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
const int maxn = 5e3 + 10;

double h[maxn];

int main(){
    for(int i = 1; i <= 5000; ++i)
        h[i] = h[i-1] + 1.0/i;
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        double ans = 0;
        for(int i = 1,x,y; i <= n; ++i){
            scanf("%d%d", &x, &y);
            if(y == 1) ans += x;
            else ans += x * h[n];
        }printf("Case %d: %f\n", ++kase, ans);
    }
	return 0;
}
