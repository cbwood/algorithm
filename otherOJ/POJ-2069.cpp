/*************************************************************************
	> File Name: POJ-2069.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年10月15日 星期一 15时18分21秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

const double eps = 1e-8;
typedef long long LL;
const int maxn = 1e2;

struct point{
	double x,y,z;
	point(double xx=0, double yy=0, double zz=0){
		x=xx;
		y=yy;
		z=zz;
	}
}a[maxn];

#define sqr(x) (x)*(x)

double dis(point p, point q){
	return sqrt(sqr(p.x-q.x)+sqr(p.y-q.y)+sqr(p.z-q.z));
}

int n;

double solve(){
	double step = 1000,ans = 1e9;
	point p;
	int s=0;
	while(step > eps){
		for(int i = 1; i <= n; ++i)
			if(dis(p,a[s]) < dis(p,a[i])) s=i;
		double tmp = dis(p,a[s]);
		ans = min(ans, tmp);
		p.x += (a[s].x-p.x)/tmp*step;
		p.y += (a[s].y-p.y)/tmp*step;
		p.z += (a[s].z-p.z)/tmp*step;
		step *= 0.98;
	}return ans;
}

int main(){
	while(scanf("%d", &n) != EOF && n){
		for(int i = 1; i <= n;++i)
			scanf("%lf %lf %lf",&a[i].x, &a[i].y, &a[i].z);
		printf("%.5f\n", solve());
	}return 0;
}
