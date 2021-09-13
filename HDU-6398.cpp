/*************************************************************************
	> File Name: HDU-6398.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月16日 星期四 07时34分57秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define sqr(x) (x)*(x)
const double eps = 1e-8;
const double pi = acos(-1.0);
const LL INF = 1e8;

int dcmp(double x){
    if(x > eps) return 1;
    if(x < -eps) return -1;
    return 0;
}

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

    bool operator < (const point &q){
        if(x == q.x) return y < q.y;
        return x < q.x;
    }

	point operator *(const double rhq){
		return point(x*rhq,y*rhq);
	}

    bool operator == (const  point &q){
        return dcmp(x-q.x) == 0 && dcmp(y -q.y) == 0;
    }

    point rotate(point p, double ang){
        point v = (*this) - p;
        double c = cos(ang), s = sin(ang);
        return point(p.x+v.x*c-v.y*s, p.y+v.x*s+v.y*c);
    }

	void read(){
		scanf("%lf%lf",&x,&y);
	}
};

double dot(point p, point q){
    return p.x*q.x + p.y*q.y;
}

double det(point p, point q){
    return p.x*q.y - p.y*q.x;
}

double cross(point p, point q){
    return det(p, q);
}

double cross(point p1, point p2, point q1, point q2){
    return det(p1-p2,q1-q2);
}

double dis(point p, point q){
    return sqrt(sqr(p.x-q.x) + sqr(p.y-q.y));
}

double dis2(point p, point q){
    return sqr(p.x-q.x) + sqr(p.y-q.y);
}

double ang(point p, point q){
	point t;
	return acos(dot(p,q)/dis(p,t)/dis(q,t));
}

point p[10];

double angle[10],len[10];

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double ans = INF;
		for(int i = 0; i < 3; ++i)
			p[i].read();
		double w;
		scanf("%lf", &w);
		for(int i = 0; i < 3;++i){
			len[i] = dis(p[(i+2)%3],p[(i+1)%3]);
			angle[i] = ang(p[(i+2)%3] - p[i], p[(i+1)%3]-p[i]);
		}
		point v(1,0),dot, ori, t;
		for(int i = 0; i < 3; ++i){
			double ang1 = angle[(i+2)%3], ang2 = angle[(i+1)%3];
			double len1 = len[(i+2)%3], len2 = len[(i+1)%3];
			if(dcmp(len[i]-w) <= 0){
				dot = (v*len1).rotate(ori,ang2);
				if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, dot.y);
				dot = (v*len2).rotate(ori,ang1);
				if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, dot.y);
			}

			double ang11 = pi/2 - ang1, ang22 = pi/2 - ang2;
			dot = (v*len1).rotate(ori,ang22);
			if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, max(len[i], dot.y));
			dot = (v*len2).rotate(ori,ang11);
			if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, max(len[i], dot.y));

			if(dcmp(len[i] - w) > 0){
				double ang3 = acos(w/len[i]);
				t = (v*len[i]).rotate(ori, ang3);
				dot = (v*len1).rotate(ori,ang2+ang3);
				if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, max(t.y, dot.y));
				dot = (v*len2).rotate(ori,ang1+ang3);
				if(dcmp(dot.x-w) <= 0 && dcmp(dot.x) >= 0 && dot.y >= 0) ans = min(ans, max(t.y, dot.y));
			}
		}if(dcmp(ans - INF) == 0) puts("impossible");
		else printf("%.9f\n", ans);
	}return 0;
}
