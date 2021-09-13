/*************************************************************************
	> File Name: cont5-I.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月21日 星期四 20时43分59秒
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
int a[205], b[205];
int dp[205][3005];

struct node{
    int x, y, id;
    node(){}
    node(int x, int y, int id)
    :x(x), y(y), id(id){}
}c[300];

int main(){
    int n, L, cnt = 0;
    scanf("%d %d", &n, &L);
    for(int i = 1; i <= n; ++i){
        scanf("%d %d", a+ i, b + i);
         c[++cnt] = node(a[i], b[i], i), dp[cnt][a[i]]++;
        if(a[i] != b[i])
            c[++cnt] = node(b[i], a[i], i), dp[cnt][b[i]]++;
    }
    for(int l = 1; l <= L; ++l)
    for(int i = 1; i <= cnt ; ++i)
        for(int j = 1; j <= cnt; ++j)
                if(c[i].id != c[j].id && dp[i][l] && c[j].x == c[i].y){
                dp[j][l+c[j].x] = (dp[j][l+c[j].x] + dp[i][l]) % mod;
            }
    int ans = 0;
    for(int i = 1; i <= cnt; ++i)
        ans = (ans + dp[i][L]) % mod;
    printf("%d\n",ans);
	return 0;
}
