/*************************************************************************
	> File Name: Lightoj-1284.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月18日 星期一 12时35分53秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define sqr(x) ((x)*(x))
typedef long long LL;

double qpow(double x, int n){
    double ans = 1;
    x = 1 - 2 * x;
    while(n){
        if(n&1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }return 0.5 * (1 - ans);
}

double cal(double  i, double n){
    return 1.0 - (sqr(n-i) + sqr(i-1)) / sqr(n);
}

int main(){
    int t, kase = 0;
    int x, y, z, K;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &x, &y, &z, &K);
        double ans = 0;
        for(int i = 1; i <= x; ++i)
            for(int j = 1; j <= y; ++j)
                 for(int k = 1; k <= z; ++k){
                    double t = cal(i, x) * cal(j, y) * cal(k, z);
                     ans =  ans + qpow(t, K);
                }
        printf("Case %d: %.7f\n",++kase, ans);
    }return 0;
}
