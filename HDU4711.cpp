/*************************************************************************
	> File Name: HDU4711.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月16日 星期一 16时03分36秒
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
const int maxn = 1e3 + 10;

const double inf = 1e50;

struct ss{
    double x;
    int pre;
}dp[1003][102];
int ww[maxn];
double p[103][103], pp[103][103];

int ans[maxn];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, w;
        scanf("%d %d %d", &n, &m, &w);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &ww[i]),ww[i]++;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; ++j){
                scanf("%lf", &p[i][j]);
                if(p[i][j] == 0) 
                    p[i][j] = -inf;
                else p[i][j] = log(p[i][j]);
            }
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= w; ++j){
                scanf("%lf", &pp[i][j]);
                if(pp[i][j] == 0)
                    pp[i][j] = -inf;
                else pp[i][j] = log(pp[i][j]);
            }
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= m; ++j)
                dp[i][j].x = -inf, dp[i][j].pre = 0;
        dp[0][1].x = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                for(int k = 1; k <= m; ++k){
                    double tmp = dp[i-1][j].x + p[j][k] + pp[k][ww[i]];
                    if(tmp > dp[i][k].x){
                        dp[i][k].x = tmp;
                        dp[i][k].pre = j;
                    }
                }
        double tmp = -inf;
        int cnt = 0,k;
        for(int i = 1; i <= m; ++i)
            if(dp[n][i].x > tmp){
            tmp = dp[n][i].x;
            k = i;
        }
        while(k){
            ans[++cnt] = k;
            k = dp[n][k].pre;
            n--;
        }
        for(int i = cnt-1; i >1; --i)
            printf("%d ", ans[i]-1);
        printf("%d\n", ans[1]-1);
    }
	return 0;
}
