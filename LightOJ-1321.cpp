/*************************************************************************
	> File Name: LightOJ-1321.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月11日 星期六 08时40分50秒
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
const int maxn = 1e4 + 10;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c = getchar(),c == EOF) return 0; //EOF
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c-'0');
    while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
	if(x > 9) out( x / 10);
	putchar( x % 10 + '0');
}

struct ss{
    int to, nx;
    double w;
}a[maxn];
int head[110];
double dis[110];
bool vis[110];
int k;

void add(int u, int v, double w){
    a[k].to = v;
    a[k].w = w;
    a[k].nx = head[u];
    head[u] = k++;
}

void init(){
    k = 0;
    for(int i = 0; i < 110; ++i)
        head[i] = -1,vis[i] =dis[i] =  0;
}

void SPFA(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for(int st = head[t]; st != -1; st = a[st].nx){
            int to = a[st].to;
            double w = a[st].w;
            if(dis[to] < dis[t] * w){
                dis[to] = dis[t] * w;
                if(!vis[to]){
                    vis[to] = 1;
                    q.push(to);
                }
            }
        }
    }
}

int main(){
    int t, kase = 0;
    scan_d(t);
    while(t--){
        init();
        int n,m,s,k;
        scan_d(n);scan_d(m);scan_d(s);scan_d(k);
        while(m--){
            int u,v,w;
            scan_d(u);scan_d(v);scan_d(w);
            add(u,v,w/100.0);
            add(v,u,w/100.0);
        }
        SPFA(0);
        double p = dis[n-1];
        double ans = 2.0*s*k/p;
        printf("Case %d: %f\n",++kase, ans);
    }
	return 0;
}
