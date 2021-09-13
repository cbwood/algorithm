/*************************************************************************
	> File Name: contest6-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月26日 星期二 19时19分27秒
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
double a, c, b, s, x, y, z;

int main(){
    scanf("%lf %lf %lf %lf",&s, &a, &b, &c);
    double d = a + b + c;
    if(a == 0 && b == 0 && c == 0){
        printf("0 0 0\n");
        return 0;
    }if(a == 0 && b == 0){
        printf("0 0 %.6f\n", s);
        return 0;
    }if(a == 0 && c == 0){
        printf("0 %.6f 0\n",s);
        return 0;
    }if(b == 0 && c == 0){
        printf("%.6f 0 0\n",s);
        return 0;
    }
    x = s/ d * a;
    y = s / d * b;
    z = s /d * c;
    printf("%.12f %.12f %.12f\n",x, y, z);
	return 0;
}
