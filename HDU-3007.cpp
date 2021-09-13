/*************************************************************************
	> File Name: HDU-3007.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月20日 星期五 15时39分36秒
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
const int maxn = 520;

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

point p[maxn];

point circumcenter(point A, point B, point C){
    point ans;
    double a1 = B.x - A.x, b1 = B.y - A.y, c1 = (sqr(a1) + sqr(b1)) / 2;
    double a2 = C.x - A.x, b2 = C.y - A.y, c2 = (sqr(a2) + sqr(b2)) / 2;
    double d = a1 * b2 - a2*b1;
    ans.x = A.x + (c1 * b2 - c2*b1) / d;
    ans.y = A.y + (a1 * c2 - a2 * c1) / d;
    return ans;
}

void min_cover_circle(point &c, double &r, int n){
    random_shuffle(p+1,p+1+n);
    c = p[1];
    r = 0;
    for(int i = 2; i <= n; ++i)
        if(dis(c, p[i]) > r + eps){
            r = 0;
            c = p[i];
            for(int j = 1; j < i; ++j)
            if(dis(c, p[j]) > eps + r){
                c.x = (p[i].x + p[j].x) / 2;
                c.y = (p[i].y + p[j].y) / 2;
                r = dis(c, p[i]);
                for(int k = 1; k < j; ++k)
                    if(dis(c, p[k]) > r + eps){
                        c = circumcenter(p[i], p[j], p[k]);
                        r = dis(c, p[i]);
                }
            }
        }
}

int main(){
    int n;
    point c;
    double r;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 1; i <= n; ++i)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        min_cover_circle(c, r, n);
    printf("%.2f %.2f %.2f\n", c.x, c.y, r);     
    }
	return 0;
}
