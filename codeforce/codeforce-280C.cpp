/*************************************************************************
	> File Name: codeforce-280C.cpp
	> Author: wood
	> Mail: cbcruel@gmail.com
	> Created Time: 2018年07月15日 星期日 15时33分35秒
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

vector<int> w[maxn];
double ans = 0;

void dfs(int u, int v, int dept){
    ans += 1.0/dept;
    for(auto x : w[u])
        if(x != v)
            dfs(x, u, dept+1);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int x, y;
        scanf("%d %d", &x, &y);
        w[x].emplace_back(y);
        w[y].emplace_back(x);
    }
    ans = 0;
    dfs(1,-1,1);
    printf("%.6f\n", ans);
	return 0;
}
