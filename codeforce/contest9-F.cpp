/*************************************************************************
	> File Name: contest9-F.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月24日 星期日 20时06分19秒
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

struct ss{
    int a, date, s;
    ss(){}
    ss(int a, int date, int s)
    :a(a), date(date), s(s){}
    bool operator < (ss &q){
        if(s != q.s)
            return s < q.s;
        if(date != q.date)
            return date > q.date;
        return a > q.a;
    }
}b[2000+10], c[2000+10];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        map<int,int > q;
        scanf("%d", &n);
        int m = n;
        for(int i = 1; i <= n; ++i){
            int x, y, z;
            scanf("%d %d/%d/%d %d", &b[i].a, &x, &y, &z, &b[i].s);
            b[i].date = ((x * 100) + y) * 100 + z;
           // printf("%d\n", b[i].date);
            c[i] = b[i];
            q[b[i].a] = 1;
        }sort(b+1, b+1+n);
        int num = 0;
        for(int i = 1; i <= n; ++i)
            if(b[i].s > 0)
                num++;
        int x = num * 0.03;
        if(x){
            for(int i = n; i > n-x; --i)
                q[b[i].a] = 6;
            n -= x;
        }x = num * 0.07;
        if(x){
            for(int i = n; i > n - x; --i)
                q[b[i].a] = 5;
            n -= x;
        }x = num * 0.2;
        if(x){
            for(int i = n; i > n - x; --i)
                q[b[i].a] = 4;
            n -= x;
        }x = num * 0.3;
        if(x){
            for(int i = n; i > n - x; --i)
                q[b[i].a] = 3;
            n -= x;
        }for(int i = n; i > 0 && b[i].s > 0; --i)
            q[b[i].a] = 2;
        for(int i = 1; i <= m; ++i)
            printf("LV%d\n", q[c[i].a]);
    }
	return 0;
}
