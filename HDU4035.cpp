/*************************************************************************
	> File Name: HDU4035.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 11时41分17秒
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
const double eps = 1e-9;
const double C = 0.57721566490153286060651209;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e4 + 10;

vector<int> w[maxn];
double a[maxn], b[maxn], c[maxn];
double k[maxn], e[maxn];

bool dfs(int u, int pre){
    int m = w[u].size();
    a[u] = k[u];
    b[u] = (1-k[u]-e[u])/m;
    c[u] = 1-k[u]-e[u];
    double tmp = 0;
    for(auto x : w[u]) 
        if(x != pre){
            if(!dfs(x,u)) return false;
            a[u] += (1-k[u]-e[u]) * a[x] / m;
            c[u] += (1-k[u]-e[u]) / m * c[x];
            tmp += (1-k[u]-e[u])/m*b[x];
        }
    if(fabs(1-tmp) < eps) return false;
    a[u] /= (1-tmp);
    b[u] /= (1-tmp);
    c[u] /= (1-tmp);
    return true;
}

int main(){
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; ++i)
            w[i].clear();
        for(int i = 1; i < n; ++i){
            int x, y;
            scanf("%d %d", &x, &y);
            w[x].emplace_back(y);
            w[y].emplace_back(x);
        }for(int i = 1; i <= n; ++i){
            scanf("%lf %lf",&k[i], &e[i]);
            k[i] /= 100;
            e[i] /= 100;
        }printf("Case %d: ", ++kase);
        if(dfs(1, -1) && fabs(1-a[1]) > eps)
            printf("%.4f\n", c[1]/(1-a[1]));
        else puts("impossible");
    }
	return 0;
}
