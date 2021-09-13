/*************************************************************************
	> File Name: codeforce197-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年01月07日 星期日 22时31分47秒
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
const int maxn = 1500 + 10;

char w[maxn][maxn];
int a[maxn][maxn][2];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y){
    if(a[x%n][y%m][0] == -1 && a[x%n][y%m][1] == -1)
        a[x%n][y%m][0] = x,a[x%n][y%m][1] = y;
    else if(a[x%n][y%m][0] != x || a[x%n][y%m][1] != y){
        puts("Yes");
        exit(0);
    }else return ;
    for(int i = 0; i < 4; ++i){
        int sx = x + dx[i];
        int sy = y + dy[i];
        if(w[sx%n][sy%m] == '.')
            dfs(sx, sy);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    int sx, sy;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j){
        scanf(" %c", &w[i][j]);
        if(w[i][j] =='S'){
            w[i][j] = '.';
            sx = i + n * m, sy = j + n * m;
        }
    }
    memset(a, -1, sizeof(a));
    dfs(sx, sy);
    puts("No");
	return 0;
}
