/*************************************************************************
	> File Name: codeforce199-C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月06日 星期六 13时30分28秒
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

double xp, yp, vp, x , y, v, r;

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

double solve(double t){
    double ang = atan2(yp , xp);
    double R = dis(xp, yp, 0, 0);
    double w = vp / R;
    double ang1 = ang + w * t;
    double xx = R*cos(ang1), yy = R*sin(ang1);
    double dis1 = dis(xx, yy, x, y);
    double dis2 = sqrt(x * x + y * y - r * r) + sqrt(xx * xx + yy * yy - r * r);
    if(dis1 < dis2)
        return dis1;
    double dis3 = dis(x, y, 0 ,0), dis4 = dis(xx, yy, 0, 0);
    double ang2 = acos((dis3 * dis3 + dis4 * dis4 - dis1*dis1) / (2 * dis3 * dis4)) - atan(sqrt(x*x + y*y-r*r) / r) - atan(sqrt(xx*xx+yy*yy-r*r)/r);
    return ang2 * r + dis2;
}

int main(){
   
    cin >> xp >> yp>> vp >> x >> y >> v >> r;
    double l = 0.0, r = 10000000;
    while(r-l > eps){
        double mid = (l+r) / 2;
        if(solve(mid) <= mid * v + eps)
            r = mid;
        else l = mid;
    }
    printf("%0.10f\n", l);
	return 0;
}
