/*************************************************************************
	> File Name: HDU-6336.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月01日 星期三 19时15分56秒
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

LL w[50][50];
int a[12], L;

LL solve(int x, int y){
    if(x < 0 || y < 0) return 0;
    return w[L-1][L-1] *(x/L) *(y/L)
    + w[L-1][y%L] * (x/L)
    + w[x%L][L-1] * (y/L)
    +w[x%L][y%L];
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &L);
        for(int i = 0; i < L; ++i)
            scanf("%d", &a[i]);
        int t = 0;
        for(int i = 0; i <= 4*L; ++i)
            for(int j = 0;j <= i; ++j)
                w[j][i-j] = a[t], t=(t+1)%L;
        L *= 2;
        for(int i = 0; i < L; ++i)
        for(int j = 0; j < L; ++j){
            if(i) w[i][j] += w[i-1][j];
            if(j) w[i][j] += w[i][j-1];
            if(i&&j) w[i][j] -= w[i-1][j-1];
        }int q;
        scanf("%d", &q);
        while(q--){
            int x0,y0,xx,yy;
            scanf("%d %d %d %d", &x0, &y0, &xx, &yy);
            printf("%lld\n", solve(xx,yy) - solve(x0-1,yy) - solve(xx,y0-1) + solve(x0-1,y0-1));
        }
    }
	return 0;
}
