/*************************************************************************
	> File Name: codeforce-48E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月04日 星期六 00时10分25秒
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
const int maxn = 2e5 + 10;

struct point{
    double x, y;
    point(double xx = 0.0, double yy = 0.0){
        x = xx;
        y = yy;
    }
    bool operator <(const point &q)const{
        return x < q.x;
    }
}p[maxn], pp[maxn], t;

double aa[maxn],sy;



double solve(point pp, point qq){
    double a,b,c;
    a = pp.y-qq.y;
    b = qq.x-pp.x;
    c = -a*pp.x-b*pp.y;
    return (-c-b*sy)/a;
}

int main(){
    double a, b;
    scanf("%lf %lf %lf", &sy, &a, &b);
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
        scanf("%lf %lf", &p[i].x ,&p[i].y);
    sort(p+1,p+1+n);
    pp[1] = p[1];
    int num = 1;
    for(int i = 2; i <= n; ++i)
        if(p[i].x - pp[num].y < eps)
            pp[num].y = p[i].y;
        else pp[++num] = p[i];
    n = num;

    for(int i = 1; i <= n; ++i)
        aa[i] = pp[i].x;
    int q;scanf("%d", &q);
    while(q--){
        scanf("%lf %lf", &t.x, &t.y);
        double ans = 0;
        int k = lower_bound(aa+1,aa+1+n, t.x)-aa; 
        for(int i = max(k-100,1); i <= n&&i <= k+100; ++i){
            double t1 = solve(point(pp[i].x,0.0),t);
            double t2 = solve(point(pp[i].y,0.0), t);
            t1 = max(t1, a);
            t2 = min(t2, b);
            ans = ans + max((t2-t1),0.0);
        }printf("%.10f\n",ans);
    }
	return 0;
}
