/*************************************************************************
	> File Name: LightOJ1058.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年11月06日 星期一 22时56分12秒
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

struct point{
    int x, y;
    bool operator <(const point &q)const{
        if(x == q.x) return y < q.y;
        return x < q.x;
    }
}a[1000+10], mid;

map<point,int> q;
int main(){
    int t, n, kase = 0;
    scanf("%d", &t);
    while(t--){
        q.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d %d", &a[i].x, &a[i].y);
        int num = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = i+1; j <= n; ++j){
                mid.x =(a[i].x + a[j].x);
                mid.y = (a[i].y + a[j].y);
                q[mid]++;
               // printf("%d  xxx ", q[mid]);
             }
        LL ans = 0;
        for(int i = 1; i <= n; ++i)
             for(int j = i+1; j <= n; ++j){
                double x = (a[i].x + a[j].x);
                double y = (a[i].y + a[j].y);
                point t;
                t.x = x;
                t.y = y;
                ans += q[t]-1;
               // printf("%d qqq ", q[t]);
            }
        printf("Case %d: %lld", ++kase, ans/2);
    }
	return 0;
}
