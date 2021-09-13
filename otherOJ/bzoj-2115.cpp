/*************************************************************************
	> File Name: bzoj-2115.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月07日 星期二 15时33分30秒
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
const LL mod = 1e9 + 7;
const int maxn = 5e4 + 10;
const int MAX_BASE = 62;
#define mp make_pair

vector<pair<int, LL> > w[maxn];
LL a[maxn*100], b[MAX_BASE+10];
LL dis[maxn];
bool vis[maxn];
int cnt;

void solve(int n) {
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i];
                    for (int k = j - 1; k >= 0; --k)
                        if (b[k] && (b[j] >> k & 1))
                            b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k)
                        if (b[k] >> j & 1)
                            b[k] ^= b[j];
                    break;
                }
            }
}

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < w[u].size(); ++i){
        pair<int, LL> x = w[u][i];
        if(!vis[x.first]){
            dis[x.first] = dis[u] ^ x.second;
            dfs(x.first);
        }else a[cnt++] = dis[u] ^ dis[x.first] ^ x.second;
    }
}

int main(){
    int n, m;
    ios::sync_with_stdio(0);
    cin >> n >> m;
    while(m--){
        int x, y;
        LL d;
        cin >> x >> y >> d;
        w[x].push_back(mp(y,d));
        w[y].push_back(mp(x,d));
    }cnt = 0;
    dfs(1);
    solve(cnt);
    LL ans = dis[n];
    for(int i = 0; i <= MAX_BASE; ++i)
        if(ans <(ans^b[i])) ans ^= b[i];
    cout << ans << endl;
	return 0;
}
