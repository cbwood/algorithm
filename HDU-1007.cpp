/*************************************************************************
	> File Name: HDU-1007.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月20日 星期五 14时04分05秒
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
#define sqr(x) (x)*(x)
typedef long long LL;
const double eps = 1e-8;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

struct point{
    double x, y;
    point(double _x = 0, double _y = 0){
        x = _x; y = _y;
    }
    point operator + (const point &q){
        return point(x+q.x, y+q.y);
    }

    point operator - (const point &q){
        return point(x-q.x, y-q.y);
    }
};

double dot(point p, point q){
    return p.x*q.x + p.y*q.y;
}

double det(point p, point q){
    return p.x*q.y - p.y*q.x;
}

double cross(point p1, point p2, point q1, point q2){
    return dot(p1-p2,q1-q2);
}

double dis(point p, point q){
    return sqrt(sqr(p.x-q.x) + sqr(p.y-q.y));
}

bool cmpx(point &q, point &p){
    return q.x < p.x;
}

bool cmpy(point &p, point &q){
    return p.y < q.y;
}

point p[maxn], tmp[maxn];

double solve(int l ,int r){
    if(l >= r) return 1e10;
    int mid = (l+r) >> 1;
    double d = min(solve(l,mid), solve(mid+1,r));
    int num = 0;
    for(int i = mid; i >= l && p[mid].x - p[i].x < d; --i)
        tmp[++num] = p[i];
    for(int i = mid+1; i <= r && p[i].x - p[mid].x < d; ++i)
        tmp[++num] = p[i];
    sort(tmp+1, tmp+1+num, cmpy);
    for(int i = 1; i <= num; ++i)
        for(int j = i+1; j <= num && tmp[j].y - tmp[i].y < d; ++j)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 1; i <= n; ++i)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p+1,p+1+n, cmpx);
        printf("%.2f\n", solve(1,n)/2);
    }
	return 0;
}
