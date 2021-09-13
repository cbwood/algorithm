/*************************************************************************
	> File Name: cf166-D.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2017年12月23日 星期六 14时52分10秒
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

map<int ,int> q;
int match[maxn];

struct node{
    int money, siz, id;
    bool operator < (node &q){
        return money > q.money;
    }
}a[maxn], b[maxn];
vector<int> edge[maxn];

int dfs(int x){
    for(int i = 0; i < edge[x].size(); ++i)
    if(match[edge[x][i]] != x){
        if(match[edge[x][i]] == -1 || dfs(match[edge[x][i]])){
            match[edge[x][i]] = x;
            return 1;
        }
    }return 0;
}

int main(){
    memset(match, -1, sizeof(match));
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d %d", &a[i].money, &a[i].siz), a[i].id = i;
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i)
        scanf("%d %d", &b[i].money, &b[i].siz);
    sort(a+1, a+1+n);
    for(int i = 1; i <= n; ++i)
        q[a[i].siz] = i;
    for(int i = 1; i <= m; ++i){
        if(q[b[i].siz+1] && b[i].money >= a[q[b[i].siz+1]].money)
            edge[q[b[i].siz+1]].push_back(i);
        if(q[b[i].siz] && b[i].money >= a[q[b[i].siz]].money)
            edge[q[b[i].siz]].push_back(i);
    }
    int num = 0;
    LL ans = 0;
    for(int i = 1; i <= n; ++i){
        if(dfs(i)){
            ans += a[i].money * 1LL;
            num++;
        }
    }cout << ans << endl << num << endl;
    for(int i = 1; i <= m; ++i)
        if(match[i] != -1)
    cout << i << ' ' << a[match[i]].id << endl;
	return 0;
}
