/*************************************************************************
	> File Name: GoodBye2017-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月30日 星期六 00时24分29秒
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
const int maxn = 1e3 + 10;

double dis(double xx, double yy){
    return sqrt(xx * xx - yy * yy);
}

double x[maxn], y[maxn];

int main(){
    int n;
    double r;
    scanf("%d %lf", &n, &r);
    for(int i = 1; i <= n; ++i)
        scanf("%lf", &x[i]);
    y[1] = r;
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j < i; ++j){
            if(fabs(x[i]-x[j]) <= 2 * r + eps)
                y[i] = max(y[i], dis(2*r, x[i]-x[j]) + y[j]);
                if(y[i] < eps) y[i] = r;
        }
    for(int i = 1; i < n; ++i)
        printf("%.10f ", y[i]);
    printf("%.10f\n", y[n]);
	return 0;
}
