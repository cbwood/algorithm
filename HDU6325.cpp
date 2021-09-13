/*************************************************************************
    > File Name: HDU6325.cpp
    > Author: wood
    > Mail: cbcruel@gmail.com
    > Created Time: 2018年07月30日 星期一 20时21分00秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<string>

using namespace std;
typedef long long  LL;
typedef long long ll;
const LL eps = 0;
const double C = 0.57721566490153286060651209;
const LL pi = acos(-1.0);
const int maxn = 2e5+10;
const int mod = 1e9 + 7;
const LL INF = 1e18;
#define sqr(x) (x)*(x)

LL dcmp(LL x){
    return x;
}

struct point{
    LL x, y;
    int id;
    point(LL _x = 0, LL _y = 0){
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

    bool operator == (const  point &q){
        return dcmp(x-q.x) == 0 && dcmp(y -q.y) == 0;
    }
};

LL dot(point p, point q){
    return p.x*q.x + p.y*q.y;
}

LL det(point p, point q){
    return p.x*q.y - p.y*q.x;
}

LL cross(point p, point q){
    return det(p, q);
}

LL cross(point p1, point p2, point q1, point q2){
    return det(p1-p2,q1-q2);
}

LL dis(point p, point q){
    return sqrt(sqr(p.x-q.x) + sqr(p.y-q.y));
}

LL dis2(point p, point q){
    return sqr(p.x-q.x) + sqr(p.y-q.y);
}

bool cmp(const point &p, const point &q){
    if(p.x != q.x) return p.x < q.x;
    if(p.y != q.y) return p.y > q.y;
    return p.id < q.id;
}



point p[maxn], q[maxn];
int ans[maxn], top, n;

 void graham()
 {
     sort(p+1,p+n+1, cmp);
     for(int i=1;i<=n;i++)
     {
         if(i > 1&& dcmp(p[i].x- p[i-1].x) == 0) continue;
         while(top > 1 && dcmp(cross(p[i], q[top], q[top],q[top-1])) < 0) top--;
         q[++top]=p[i];
     }
 }

bool vis[maxn];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        top = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%lld %lld", &p[i].x, &p[i].y), p[i].id = i;
        graham();
        int num = top;
        memset(vis, 0, sizeof vis);
        vis[1] = vis[top] = 1;
        for(int i = 2; i < num; ++i)
            if(dcmp(cross(q[i]-q[i-1], q[i+1]-q[i])))
                vis[i] = 1;

        for(int i = top; i > 0; --i)
            if(vis[i])
                ans[i] = q[i].id;
            else ans[i] = min(ans[i+1],q[i].id);
        for(int i = 1; i < top; ++i)
            if(ans[i] == q[i].id)
                printf("%d ", ans[i]);
        printf("%d\n",ans[top]);
    }return 0;
}
