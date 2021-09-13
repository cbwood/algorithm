/*************************************************************************
	> File Name: codeforce-75C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月26日 星期四 08时28分53秒
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

bool vis[maxn];
vector<int> q;

void init(int a, int b){
    int t = sqrt(a+0.5);
    for(int i = 1; i <= t; ++i)
        if(a % i == 0){
            q.emplace_back(i);
            if(i*i != a)
                q.emplace_back(a/i);
        }
    t = sqrt(b+0.5);
    for(int i = 1; i <= t; ++i)
        if(b % i == 0){
            if((i < maxn)) vis[i] = 1;
            if(b/i < maxn) vis[b/i] = 1;
        }
}

int main(){
    int a, b ,n;
    scanf("%d %d", &a, &b);
    init(a, b);
    sort(q.begin(),q.end());
    int ans = 1;
    reverse(q.begin(),q.end());
    for(auto x : q){
        if(x < maxn &&  vis[x]) ans = max(ans, x);
        if(b%x == 0 && b/x < maxn && vis[b/x]) ans = max(ans, b/x);
        if(ans  > 1) break;
    }printf("%d\n", ans);
	return 0;
}
