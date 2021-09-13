/*************************************************************************
	> File Name: codeforce-499C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月26日 星期四 23时26分49秒
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
const int maxn = 1e3 + 10;

double a[maxn], b[maxn];
int n, m;

bool check(double x){
    for(int i = 1; i < n; ++i){
            x = x - (x+m)/a[i];
            x = x - (x+m)/b[i+1];
        if(x < eps) return false; 
    }x = x - (x+m)/a[n];
    x = x-(x+m)/b[1];
    return x > 0;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%lf", &a[i]);
    for(int i = 1; i <= n; ++i)
        scanf("%lf", &b[i]);
    double r = 1e9+1,l = 0;
    int t = 100;
    while(t--){
        double mid = (r+l)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(fabs(1e9+1-r) < eps) r = -1;
    printf("%.10f\n", r);
	return 0;
}
