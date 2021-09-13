/*************************************************************************
	> File Name: contest3-E.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年10月29日 星期日 18时05分30秒
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
const int maxn = 500 + 10;

char w[maxn][maxn];
bool vis[maxn];
struct ss{
    int x, y;
    char s;
    ss(){};
    ss(int x, int y, char s)
    :x(x), y(y), s(s){};
}a[maxn * 2000];
int n, m, k;

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

bool judge(int x, int y){
    if(x < 1 || y < 1 || x > n ||y > m)
        return false;
    if( x - 1 > 0 && w[x - 1][y] == 'B')
        return true;
    if( x + 1 <= n && w[x + 1][y] == 'B')
        return true;
    if( y - 1 > 0 && w[x][y - 1] == 'B')
        return true;
    if( y + 1 <= m && w[x][y + 1] == 'B')
        return true;
    return false;
}

void BFS(int x, int y){
        w[x][y] = 'R';
        for(int i = 0; i < 4; ++i){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx > 0 && ty > 0 && tx <= n && ty <= m && w[tx][ty] == 'B')
            {
                w[tx][ty] = 'R';
                BFS(tx, ty);
                a[++k] = ss(tx, ty, 'D');
                a[++k] = ss(tx, ty, 'R');
            }
        }
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i =  1; i <= n; ++i)
        scanf(" %s", w[i]+1);
    k = 0;
    char ch;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(w[i][j] == '.'){
                ch = 'B';
                w[i][j] = ch;
                a[++k] = ss(i,j,ch);
            }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(w[i][j] == 'B')
                if(judge(i, j))
                    BFS(i, j);
    printf("%d\n", k);
    for(int i = 1; i <= k; ++i)
        printf("%c %d %d\n", a[i].s, a[i].x, a[i].y);
	return 0;
}
