/*************************************************************************
	> File Name: POJ3744.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年09月16日 星期六 09时34分13秒
 ************************************************************************/

#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;
const double eps = 1e-9;

struct mat{
    double a[3][3];
    mat (){a[1][1] = a[1][2] = a[2][1] = a[2][2] = 0.0; }
    mat operator *(mat &q){
        mat c;
        for(int i = 1; i <= 2; ++i)
            for(int k = 1; k <= 2; ++k)
                for(int j = 1; j <= 2; ++j)
                    c.a[i][j] += a[i][k] * q.a[k][j];
        return c;
    }
};

mat qpow(mat x, LL n){
    mat ans;
    ans.a[1][1] = ans.a[2][2] = 1.0;
    while(n){
        if(n&1) ans = ans * x;
        x = x * x;
        n >>= 1;
    }return ans;
}

int a[20];

int main(){
    int n;
    double p;
    while(scanf("%d %lf", &n, &p) != EOF){
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        double ans = 1.0;
        mat tmp;
        double t1 = p;
        double t2 = p *p + 1 - p;
        tmp.a[1][1] = p;
        tmp.a[1][2] = 1 - p;
        tmp.a[2][1] = 1;
        mat t;
        t = qpow(tmp, a[1] - 1);
        ans *=(1 - t.a[1][1]);
        for(int i = 2; i <= n; ++i){
            if(a[i] == a[i-1])
                continue;
            t = qpow(tmp, a[i] - a[i-1] - 1);
            ans *=(1 - t.a[1][1]);
        }
        printf("%.7f\n", ans);
    }return 0;
}

