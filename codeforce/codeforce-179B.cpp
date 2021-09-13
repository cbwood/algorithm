/*************************************************************************
	> File Name: codeforce-179B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月24日 星期二 14时27分18秒
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
int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
# define FOR(i, a, b) for (int i = a; i <= b; ++ i)
# define REP(i, n) FOR (i, 1, n)
# define REP_0N(i, n) FOR (i, 0, n)
# define NR 110
const double inf = 1e9;
int n, m, type, id[NR], tp[NR]; double a[NR][NR];
void pivot (int r, int c) {
	swap (id[r + n], id[c]);
	double t = -a[r][c]; a[r][c] = -1; for(int i = 0; i <= n; ++i) a[r][i] /= t;
	for(int i = 0; i <= m; ++i) if (a[i][c] && r != i) { t = a[i][c]; a[i][c] = 0; for(int j = 0; j <= n; ++j) a[i][j] += t * a[r][j]; }
}
void solve () {
	double t; for(int i = 1; i <= n; ++i) id[i] = i;
	while (true) {
		int i = 0, j = 0; double _w = -eps;
		for(int k = 1; k <= m; ++k) if (a[k][0] < _w) _w = a[i = k][0]; if (!i) break;
		for(int k = 1; k <= n; ++k) if (a[i][k] > eps) { j = k; break; } //if (!j) { printf ("Infeasible"); return; }
		pivot (i, j);
	}
	while (true) {
		int i = 0, j = 0; double _w = eps;
		for(int k = 1; k <= n; ++k) if (a[0][k] > _w) _w = a[0][j = k]; if (!j) break; _w = inf;
		for(int k = 1; k <= m; ++k)if (a[k][j] < -eps && (t = -a[k][0] / a[k][j]) < _w) _w = t, i = k;// if (!i) { printf ("Unbounded"); return; }
		pivot (i, j);
	}
	printf ("Nasa can spend %.0f taka.\n", ceil(m*a[0][0]));
	for(int i = n+1; i <= n+m; ++i) tp[id[i]] = i - n;
	if (type) for(int i = 1; i <= n; ++i) printf ("%.9f ", tp[i] ? a[tp[i]][0] : 0);
}
int main () {
	while(scanf ("%d%d", &n, &m)!=EOF){
        type = 0;
        memset(a, 0, sizeof a);
        memset(tp, 0, sizeof tp);
	    for(int i = 1; i <= n; ++i) scanf ("%lf", &a[0][i]);
	    for(int i = 1; i <= m; ++i) { for(int j = 1; j <= n; ++j) scanf ("%lf", &a[i][j]), a[i][j] *= -1; scanf ("%lf", &a[i][0]); }
	    solve ();
    }return 0;
}
