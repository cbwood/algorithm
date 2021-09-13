/*************************************************************************
	> File Name: HDU2204.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月31日 星期二 12时51分51秒
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
const int maxn = 1e5 + 10;

int ans[1<<21];
struct ss{
    int minx,miny,maxx,maxy;
}p[22];

void dfs(int pos, int sta, int minx,int miny, int maxx, int maxy, int t){
    if(minx >= maxx || miny >= maxy) return ;
    if(pos == -1){
        if(sta)
            for(int i = 1; i < (1<<20); ++i)
                if((i&sta) == sta)
                    ans[i] += t * (maxx-minx)*(maxy-miny);
        return ;
    }dfs(pos-1,sta,minx,miny,maxx,maxy,t);
    minx = max(minx, p[pos].minx);
    miny = max(miny, p[pos].miny);
    maxx = min(maxx, p[pos].maxx);
    maxy = min(maxy, p[pos].maxy);
    dfs(pos-1, sta|(1<<pos), minx, miny,maxx, maxy,-t);
}

int main(){
    int n, m, kase = 0, ase = 0;
    while(scanf("%d %d", &n, &m)!=EOF &&(n||m)){
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; ++i)
            scanf("%d %d %d %d",&p[i].minx, &p[i].miny, &p[i].maxx, &p[i].maxy);
        dfs(n-1, 0, 0,0,mod,mod, -1);
        printf("Case %d:\n", ++kase);
        ase = 0;
        while(m--){
            scanf("%d", &n);
            int t = 0;
            while(n--){
                int x;
                scanf("%d",&x);
                t |= (1 << (x-1));
            }printf("Query %d: %d\n", ++ase, ans[t]);
        }
        puts("");
    }
}
