/*************************************************************************
	> File Name: codeforce-986A.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月25日 星期三 09时20分25秒
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
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

vector<int> w[maxn];
int a[maxn];
bool vis[maxn];

int bfs(int x, int n, int z){
    if(z == 1) return 0;
    queue<pair<int,int>> que;
    que.push(make_pair(x,0));
    set<int> s;
    memset(vis, 0, sizeof vis);
    vis[x] = 1;
    int ans = 0;
    vector<int>::iterator it;
    s.insert(a[x]);
    while(!que.empty()){
        pair<int,int> t = que.front();
        que.pop();
        for(it = w[t.first].begin(); it != w[t.first].end(); ++it)
            if(!vis[*it]){
                ans += t.second +1;
                vis[*it] = 1;
                s.insert(a[*it]);
                if(s.size() == z) return ans;
                que.push(make_pair(*it,t.second+1));
        }
    }
}

int main(){
    int n, m, k, s;
    scanf("%d %d %d %d", &n, &m, &k, &s);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        w[x].emplace_back(y);
        w[y].emplace_back(x);
    }
    for(int i = 1; i <= n; ++i)
        printf("%d ", bfs(i,n,s));
	return 0;
}
