/*************************************************************************
	> File Name: cont5-H.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月21日 星期四 22时37分05秒
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

int main(){
    int n;
    double a, d;
    scanf("%d %lf %lf", &n, &a, &d);
    double last = -1e9;
    while(n--){
        double tt, v;
        scanf("%lf %lf", &tt, &v);
        double ans= tt, tmp;
        double t = v / a;
        if(1.0 / 2 *a * t * t >= d){
            ans =ans + sqrt(2 * d / a);
        }else {
            ans = ans + t + (d - v / 2 * t) / v;
        }if(last > ans) ans = last;
        printf("%.4f\n", ans);
        last = ans;
    }
	return 0;
}
