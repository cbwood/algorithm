/*************************************************************************
	> File Name: contest9-A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月24日 星期日 19时29分50秒
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

char w[40][40];
bool vis[40][40][5], v[40][40];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int ans, n;

struct ss{
    int x, y;
    ss(){}
    ss(int x, int y)
    :x(x), y(y){}
}a[2000];

bool judge(int x, int y, int i){
    if(i == 1 && (x-1 == 0 || w[x-1][y] == '#'))
        return true;
    if(i == 2 && (x+1 == n +1 || w[x+1][y] == '#'))
        return true;
    if(i == 3 && (y - 1 == 0 || w[x][y-1] == '#'))
        return true;
    if(i == 4 && (y+1 == n + 1 || w[x][y+1] == '#'))
        return true;
    return false;
        
}

bool judge1(int x, int y){
    if(v[x][y] || x < 1 || x > n || y < 1 || y > n || w[x][y] == '#')
        return false;
    return true;
}

void bfs(int sx, int sy){
    int head = 0, tail = 1;
    v[sx][sy] = true;
    a[tail] = ss(sx,sy);
    while(head < tail){
        ss q = a[++head];
        for(int i = 1; i <= 4; ++i)
            if(!vis[q.x][q.y][i] && judge(q.x, q.y, i))
                ans++, vis[q.x][q.y][i] = true;
        for(int i = 0; i <= 3; ++i){
            int x = q.x + dx[i];
            int y = q.y + dy[i];
            if(judge1(x, y)){
                v[x][y] = true;
                a[++tail] = ss(x, y);
            }
        }
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; ++i)
            scanf(" %s", w[i]+1);
        ans = 0;
        memset(vis, false, sizeof(vis));
        memset(v, false, sizeof(v));
        bfs(1,1);
        bfs(n, n);
        printf("%d\n", 9 * (ans - 4));
    }
	return 0;
}
