/*************************************************************************
	> File Name: LightOJ-1356.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年08月08日 星期三 08时26分16秒
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
const int maxn = 5e5 + 10;

vector<int> pri;
bool vis[maxn],check[maxn];
int cnt;
vector<int> a;

template <class T>
inline bool scan_d(T &ret) {
    char c; int sgn;
    if(c = getchar(),c == EOF) return 0; //EOF
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c-'0');
    while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x) {
	if(x > 9) out( x / 10);
	putchar( x % 10 + '0');
}

void prime(){
    cnt = 0;
    for(int i = 2; i < maxn; ++i){
        if(!vis[i]) pri.push_back(i);
        for(auto &x : pri){
            if(x * i >= maxn) break;
            vis[i*x] = 1;
            if(i % x == 0) break;
        }
    }
}

bool solve(int n){
    int t = sqrt(n+0.5);
    for(int i = 1; i <= t; ++i){
        if(n%i == 0 && i *i != n){
            if(vis[n/i] && check[i]) return false;
            if(check[n/i] && vis[i]) return false;
        }
    }return true;
}

int main(){
    prime();
    int t, kase = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        a.clear();
        memset(check, 0, sizeof check);
        scanf("%d", &n);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            check[x] = 1;
            a.emplace_back(x);
        }sort(a.begin(),a.end());
        for(auto &x : a){
            if(solve(x)) ans++;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }return 0;
}
