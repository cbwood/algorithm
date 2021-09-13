/*************************************************************************
	> File Name: GoodBye2017-B.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月30日 星期六 00时00分05秒
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
const int maxn = 50 + 10;

char w[maxn][maxn], s[maxn*2];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int a[5];
int n, m , sx, sy, ex, ey;

bool bfs(){
    int x = sx, y = sy;
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
         x = x + dx[a[s[i]-'0']];
        y = y + dy[a[s[i]-'0']];
        if(x <= 0 || x > n || y <= 0 || y > m || w[x][y] == '#')
            return false;
        if(w[x][y] == 'E')
            return true;
    }return false;
}

int main(){
    for(int i = 1; i <= 4; ++i)
        a[i] = i;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j){
        scanf(" %c", &w[i][j]);
        if(w[i][j] == 'S')
            sx = i, sy = j;
        if(w[i][j] == 'E')
            ex = i, ey = j;
    }int ans = 0;
    scanf(" %s", s);
    do{
        if(bfs()) ans++;
    }while(next_permutation(a, a+4));
    printf("%d\n", ans);
	return 0;
}
